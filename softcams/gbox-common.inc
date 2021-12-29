# Stuff applying to all gbox on image
SUMMARY_${PN} = "gbox.net ${PKGV}"
DESCRIPTION_${PN} = "A binary only softcam"

PR = "r4.2"

LICENSE = "CLOSED"
require conf/license/license-close.inc
require softcam.inc
require softcam-binary-32bit.inc

FILESEXTRAPATHS:prepend := "${THISDIR}/enigma2-plugin-softcams-gbox:"

SRC_URI = " \
            file://gbox_versions/ \
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

FILES:${PN} += "/var/keys /tmp"
CONFFILES:${PN} = "/var/keys"

PACKAGE_ARCH = "${DEFAULTTUNE}"
CAM_ARCH="arm"
CAM_ARCH:sh4="sh4"
CAM_ARCH:mipsel="mips32el"

do_install() {
    cp ${S}/../init.gbox ${S}/init.${CAMNAME}

    install -d ${D}/usr/bin
    install -m 0755 ${WORKDIR}/gbox_versions/gbox_${PV}_${CAM_ARCH} ${D}/usr/bin/${CAMNAME}
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

pkg_postinst:${PN}:prepend () {
	if [ -e "$D/tmp/libnxp.so" ] && [ ! -e "$D/lib/libnxp.so" ] && [ ! -e "$D/usr/lib/libnxp.so" ]; then
		mv $D/tmp/libnxp.so $D/usr/lib/libnxp.so 2>/dev/null
	fi
	if [ ! -e "$D/lib/ld-linux.so.3" ] && [ -e "$D/lib/ld-linux-armhf.so.3" ]; then
		ln -s ld-linux-armhf.so.3 $D/lib/ld-linux.so.3
	fi
}

RDEPENDS:${PN}_aarch64 = "lib32-glibc lib32-libgcc softcam-support"

do_prepare_recipe_sysroot[noexec] = "1"
INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
deltask do_populate_sysroot
INSANE_SKIP:${PN} += "already-stripped ldflags"
INSANE_SKIP:${PN}_aarch64 += "already-stripped arch ldflags"
