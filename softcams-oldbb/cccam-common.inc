SUMMARY_${PN} = "CCcam ${PKGV}"
DESCRIPTION_${PN} = "An outdated binary only softcam"

FILESEXTRAPATHS_prepend := "${THISDIR}/../softcams/enigma2-plugin-softcams-cccam:"

CONFFILES_${PN} ?= "/etc/CCcam.cfg /etc/ppanels/CCcam.xml"

RDEPENDS_${PN} = "glibc libstdc++"
RDEPENDS_${PN}_aarch64 = ""
#RDEPENDS_${PN}_aarch64 = "lib32-libstdc++"

RPROVIDES_${PN} += "enigma2-plugin-softcams-cccam-2.0.9 enigma2-plugin-softcams-cccam-2.0.11 enigma2-plugin-softcams-cccam-2.1.1 enigma2-plugin-softcams-cccam-2.2.1 enigma2-plugin-softcams-cccam-2.3.0 enigma2-plugin-softcams-cccam-2.3.2"
RREPLACES_${PN} += "enigma2-plugin-softcams-cccam-2.0.9 enigma2-plugin-softcams-cccam-2.0.11 enigma2-plugin-softcams-cccam-2.1.1 enigma2-plugin-softcams-cccam-2.2.1 enigma2-plugin-softcams-cccam-2.3.0 enigma2-plugin-softcams-cccam-2.3.2"
RCONFLICTS_${PN} += "enigma2-plugin-softcams-cccam-2.0.9 enigma2-plugin-softcams-cccam-2.0.11 enigma2-plugin-softcams-cccam-2.1.1 enigma2-plugin-softcams-cccam-2.2.1 enigma2-plugin-softcams-cccam-2.3.0 enigma2-plugin-softcams-cccam-2.3.2"
