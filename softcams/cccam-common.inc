# Stuff applying to all CCcams on image
SUMMARY_${PN} = "CCcam ${PKGV}"
DESCRIPTION_${PN} = "An outdated binary only softcam"

PR = "r1-de"

LICENSE = "CLOSED"
require conf/license/license-close.inc
require softcam.inc
require softcam-binary-32bit.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/enigma2-plugin-softcams-cccam:"

SRC_URI = " \
            file://CCcam_${PV}_* \
            file://CCcam.cfg \
            file://CCcam.xml \
"

CONFFILES_${PN} ?= "/etc/CCcam.cfg /etc/ppanels/CCcam.xml"

PACKAGE_ARCH = "${DEFAULTTUNE}"

do_install() {
    install -d ${D}/usr/bin
    install -m 0755 ${WORKDIR}/CCcam_${PV}_${TARGET_ARCH} ${D}/usr/bin/${CAMNAME}
    install -d ${D}/etc
    install -m 0755 ${WORKDIR}/CCcam.cfg ${D}/etc/CCcam.cfg
    install -d ${D}/etc/ppanels
    install -m 0644 ${WORKDIR}/CCcam.xml ${D}/etc/ppanels/CCcam.xml
}

ASSUME_SHLIBS_aarch64 += "libc.so.6:lib32-glibc"
ASSUME_SHLIBS_aarch64 += "libpthread.so.0:lib32-glibc"
ASSUME_SHLIBS_aarch64 += "libstdc++.so.6:lib32-libstdc++"
ASSUME_SHLIBS_aarch64 += "libcrypt.so.1:lib32-libxcrypt"

INHIBIT_PACKAGE_STRIP = "1"
INSANE_SKIP_${PN} = "already-stripped build-deps"
INSANE_SKIP_${PN}_aarch64 = "already-stripped arch build-deps"

RPROVIDES_${PN} += "enigma2-plugin-softcams-cccam-2.0.9 enigma2-plugin-softcams-cccam-2.0.11 enigma2-plugin-softcams-cccam-2.1.1 enigma2-plugin-softcams-cccam-2.2.1 enigma2-plugin-softcams-cccam-2.3.0 enigma2-plugin-softcams-cccam-2.3.2"
RREPLACES_${PN} += "enigma2-plugin-softcams-cccam-2.0.9 enigma2-plugin-softcams-cccam-2.0.11 enigma2-plugin-softcams-cccam-2.1.1 enigma2-plugin-softcams-cccam-2.2.1 enigma2-plugin-softcams-cccam-2.3.0 enigma2-plugin-softcams-cccam-2.3.2"
RCONFLICTS_${PN} += "enigma2-plugin-softcams-cccam-2.0.9 enigma2-plugin-softcams-cccam-2.0.11 enigma2-plugin-softcams-cccam-2.1.1 enigma2-plugin-softcams-cccam-2.2.1 enigma2-plugin-softcams-cccam-2.3.0 enigma2-plugin-softcams-cccam-2.3.2"
