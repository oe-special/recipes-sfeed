# Stuff applying to all scams on image
SUMMARY_${PN} = "scam ${PKGV}"
DESCRIPTION_${PN} = "An outdated binary only softcam"

PR = "r0"

LICENSE = "CLOSED"
require conf/license/license-close.inc

FILESEXTRAPATHS:prepend := "${THISDIR}/enigma2-plugin-softcams-scam:"

SRC_URI = " \
            file://scam_versions/ \
"

require softcam.inc

#CONFFILES:${PN} ?= "/etc/CCcam.cfg /etc/ppanels/CCcam.xml"

do_install() {
    install -d ${D}/usr/bin
    install -m 0755 ${WORKDIR}/scam_versions/scam_${PV}_${TARGET_ARCH} ${D}/usr/bin/${CAMNAME}
}

RDEPENDS_${PN} += "libcrypto-compat-0.9.7 glibc softcam-support"
#RRECOMMENDS_${PN} += "libcrypt1"

INHIBIT_PACKAGE_STRIP = "1"
INSANE_SKIP:${PN} = "already-stripped build-deps file-rdeps"

RPROVIDES:${PN} += "enigma2-plugin-softcams-scam-3.60 enigma2-plugin-softcams-scam-3.59"
RREPLACES:${PN} += "enigma2-plugin-softcams-scam-3.60 enigma2-plugin-softcams-scam-3.59"
RCONFLICTS:${PN} += "enigma2-plugin-softcams-scam-3.60 enigma2-plugin-softcams-scam-3.59"
