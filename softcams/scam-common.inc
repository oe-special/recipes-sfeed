# Stuff applying to all scams on image
SUMMARY_${PN} = "scam ${PKGV}"
DESCRIPTION_${PN} = "An outdated binary only softcam"

PR = "r0"

LICENSE = "CLOSED"
require conf/license/license-close.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/enigma2-plugin-softcams-scam:"

SRC_URI = " \
            file://scam_${PV}_* \
"

require softcam.inc

#CONFFILES_${PN} ?= "/etc/CCcam.cfg /etc/ppanels/CCcam.xml"

PACKAGE_ARCH = "${DEFAULTTUNE}"

do_install() {
    install -d ${D}/usr/bin
    install -m 0755 ${WORKDIR}/scam_${PV}_${TARGET_ARCH} ${D}/usr/bin/${CAMNAME}
}

RDEPENDS_${PN} += "libcrypto-compat-0.9.7 glibc softcam-support"
#RRECOMMENDS_${PN} += "libcrypt1"

INHIBIT_PACKAGE_STRIP = "1"
INSANE_SKIP_${PN} = "already-stripped build-deps file-rdeps"

RPROVIDES_${PN} += "enigma2-plugin-softcams-scam-3.60 enigma2-plugin-softcams-scam-3.59"
RREPLACES_${PN} += "enigma2-plugin-softcams-scam-3.60 enigma2-plugin-softcams-scam-3.59"
RCONFLICTS_${PN} += "enigma2-plugin-softcams-scam-3.60 enigma2-plugin-softcams-scam-3.59"
