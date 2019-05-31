# Stuff applying to all CCcams on image
SUMMARY = "CCcam ${PV} softcam"
LICENSE = "CLOSED"
require conf/license/license-close.inc

require softcam.inc

PR = "r0-de"

FILESEXTRAPATHS_prepend := "${THISDIR}/enigma2-plugin-softcams-cccam:"

SRC_URI = " \
            file://CCcam_${PV}_* \
            file://CCcam.cfg \
"

CONFFILES_${PN} ?= "/etc/CCcam.cfg"

PACKAGE_ARCH = "${DEFAULTTUNE}"

do_install() {
    install -d ${D}/usr/bin
    install -m 0755 ${WORKDIR}/CCcam_${PV}_${TARGET_ARCH} ${D}/usr/bin/${CAMNAME}
    install -d ${D}/etc
    install -m 0755 ${WORKDIR}/CCcam.cfg ${D}/etc/CCcam.cfg
}

INSANE_SKIP_${PN} += "already-stripped file-rdeps arch"
INHIBIT_PACKAGE_STRIP = "1"
