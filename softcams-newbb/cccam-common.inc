SUMMARY:${PN} = "CCcam ${PKGV}"
DESCRIPTION:${PN} = "An outdated binary only softcam"

FILESEXTRAPATHS:prepend := "${THISDIR}/../softcams/enigma2-plugin-softcams-cccam:"

CONFFILES:${PN} ?= "/etc/CCcam.cfg /etc/ppanels/CCcam.xml"

RDEPENDS:${PN} = "glibc libstdc++"
RDEPENDS:${PN}:aarch64 = ""

RPROVIDES:${PN} += "enigma2-plugin-softcams-cccam-2.0.9 enigma2-plugin-softcams-cccam-2.0.11 enigma2-plugin-softcams-cccam-2.1.1 enigma2-plugin-softcams-cccam-2.2.1 enigma2-plugin-softcams-cccam-2.3.0 enigma2-plugin-softcams-cccam-2.3.2"
RREPLACES:${PN} += "enigma2-plugin-softcams-cccam-2.0.9 enigma2-plugin-softcams-cccam-2.0.11 enigma2-plugin-softcams-cccam-2.1.1 enigma2-plugin-softcams-cccam-2.2.1 enigma2-plugin-softcams-cccam-2.3.0 enigma2-plugin-softcams-cccam-2.3.2"
RCONFLICTS:${PN} += "enigma2-plugin-softcams-cccam-2.0.9 enigma2-plugin-softcams-cccam-2.0.11 enigma2-plugin-softcams-cccam-2.1.1 enigma2-plugin-softcams-cccam-2.2.1 enigma2-plugin-softcams-cccam-2.3.0 enigma2-plugin-softcams-cccam-2.3.2"
