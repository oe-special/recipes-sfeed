# Stuff applying to all gbox on image
SUMMARY = "gbox.net ${PV} softcam"
LICENSE = "CLOSED"
require conf/license/license-close.inc

require softcam.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/enigma2-plugin-softcams-gbox:"

SRC_URI = " \
            file://gbox_${PV}_* \
            file://init.gbox \
            \
            file://libnxp.so.arm \
            \
            file://conax \
            file://constcw \
            file://crypto \
            file://cwshare.cfg \
            file://cwshare.rules \
            file://drecrypt \
            file://gbox.cfg \
            file://gbox.pmc \
            file://ignore.list \
            file://irdeto \
            file://nagra \
            file://nds \
            file://powervu \
            file://seca \
            file://softcam.cfg \
            file://via \
"

INHIBIT_PACKAGE_STRIP = "1"

FILES_${PN} += "/var/keys /tmp"
CONFFILES_${PN} = "/var/keys"

PACKAGE_ARCH = "${DEFAULTTUNE}"

CAM_ARCH="arm"
CAM_ARCH_sh4="sh4"
CAM_ARCH_mipsel="mips32el"


do_configure_append() {
    cp ${S}/../init.gbox ${S}/init.${CAMNAME}
}

do_install() {
    install -d ${D}/usr/bin
    install -m 0755 ${WORKDIR}/gbox_${PV}_${CAM_ARCH} ${D}/usr/bin/${CAMNAME}
    if [ "x${CAM_ARCH}" == "xarm" ]; then
        install -d ${D}/tmp
        install -m 0755 ${WORKDIR}/libnxp.so.arm ${D}/tmp/libnxp.so
    fi
    install -d ${D}/var/keys
    for CFG in conax constcw crypto cwshare.cfg cwshare.rules drecrypt gbox.cfg gbox.pmc ignore.list irdeto nagra nds powervu seca softcam.cfg via
    do
        install -m 0755 ${WORKDIR}/$CFG ${D}/var/keys
    done

}

pkg_postinst_${PN}_prepend () {
	if [ -e "$D/tmp/libnxp.so" ] && [ ! -e "$D/lib/libnxp.so" ] && [ ! -e "$D/usr/lib/libnxp.so" ]; then
		mv $D/tmp/libnxp.so $D/usr/lib/libnxp.so 2>/dev/null
	fi
	if [ ! -e "$D/lib/ld-linux.so.3" ] && [ -e "$D/lib/ld-linux-armhf.so.3" ]; then
		ln -s ld-linux-armhf.so.3 $D/lib/ld-linux.so.3
	fi
}

INSANE_SKIP_${PN} += "already-stripped file-rdeps arch"

