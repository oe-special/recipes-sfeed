# Stuff applying to all CCcams on image
SUMMARY_${PN} = "CCcam ${PKGV}"
DESCRIPTION_${PN} = "An outdated binary only softcam"

PR = "r1-de"

LICENSE = "CLOSED"
require conf/license/license-close.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/enigma2-plugin-softcams-cccam:"

SRC_URI = " \
            file://cccam_versions \
            file://CCcam.cfg \
            file://CCcam.xml \
"

require softcam.inc
require softcam-binary-32bit.inc

CONFFILES_${PN} ?= "/etc/CCcam.cfg /etc/ppanels/CCcam.xml"

PACKAGE_ARCH = "${DEFAULTTUNE}"

do_install() {
    install -d ${D}/usr/bin
    install -m 0755 ${WORKDIR}/cccam_versions/CCcam_${PV}_${TARGET_ARCH} ${D}/usr/bin/${CAMNAME}
    install -d ${D}/etc
    install -m 0755 ${WORKDIR}/CCcam.cfg ${D}/etc/CCcam.cfg
    install -d ${D}/etc/ppanels
    install -m 0644 ${WORKDIR}/CCcam.xml ${D}/etc/ppanels/CCcam.xml
}

RDEPENDS_${PN} = "glibc libstdc++ softcam-support"
RDEPENDS_${PN}_aarch64 = "lib32-glibc lib32-libstdc++ softcam-support"

# libxcrypt

do_prepare_recipe_sysroot[noexec] = "1"
INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
deltask do_populate_sysroot
INSANE_SKIP_${PN} = "already-stripped build-deps file-rdeps"
INSANE_SKIP_${PN}_aarch64 = "already-stripped arch build-deps file-rdeps"

RPROVIDES_${PN} += "enigma2-plugin-softcams-cccam-2.0.9 enigma2-plugin-softcams-cccam-2.0.11 enigma2-plugin-softcams-cccam-2.1.1 enigma2-plugin-softcams-cccam-2.2.1 enigma2-plugin-softcams-cccam-2.3.0 enigma2-plugin-softcams-cccam-2.3.2"
RREPLACES_${PN} += "enigma2-plugin-softcams-cccam-2.0.9 enigma2-plugin-softcams-cccam-2.0.11 enigma2-plugin-softcams-cccam-2.1.1 enigma2-plugin-softcams-cccam-2.2.1 enigma2-plugin-softcams-cccam-2.3.0 enigma2-plugin-softcams-cccam-2.3.2"
RCONFLICTS_${PN} += "enigma2-plugin-softcams-cccam-2.0.9 enigma2-plugin-softcams-cccam-2.0.11 enigma2-plugin-softcams-cccam-2.1.1 enigma2-plugin-softcams-cccam-2.2.1 enigma2-plugin-softcams-cccam-2.3.0 enigma2-plugin-softcams-cccam-2.3.2"
