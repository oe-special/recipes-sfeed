# Stuff applying to all mgcamd on image
SUMMARY = "mgcamd ${PV} softcam"
LICENSE = "CLOSED"
require conf/license/license-close.inc

require softcam.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/enigma2-plugin-softcams-mgcamd:"

SRC_URI = " \
            file://mgcamd_${PV}_* \
            file://init.mgcamd \
"

#CONFFILES_${PN} ?= "/etc/CCcam.cfg"

PACKAGE_ARCH = "${DEFAULTTUNE}"
CAM_ARCH="arm"
CAM_ARCH_mipsel="mips32el"
CAM_ARCH_sh4="sh4"

PR="r3"

do_configure() {
    cp ${S}/../init.mgcamd ${S}/init.${CAMNAME}
}

do_install() {
    install -d ${D}/usr/bin
    install -m 0755 ${S}/../mgcamd_${PV}_${CAM_ARCH} ${D}/usr/bin/${CAMNAME}
}

pkg_postinst_${PN}_prepend () {
	if [ ! -e "$D/lib/ld-linux.so.3" ] && [ -e "$D/lib/ld-linux-armhf.so.3" ]; then
		ln -s ld-linux-armhf.so.3 $D/lib/ld-linux.so.3
	fi
}

INSANE_SKIP_${PN} += "already-stripped file-rdeps arch ldflags build-deps"
INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
