SUMMARY:${PN} = "scam ${PKGV}"
DESCRIPTION:${PN} = "An outdated binary only softcam"

FILESEXTRAPATHS:prepend := "${THISDIR}/../softcams/enigma2-plugin-softcams-scam:"

RDEPENDS:${PN} += "libcrypto-compat-0.9.7 glibc"
RDEPENDS:${PN}:aarch64 += ""

RPROVIDES:${PN} += "enigma2-plugin-softcams-scam-3.60 enigma2-plugin-softcams-scam-3.59"
RREPLACES:${PN} += "enigma2-plugin-softcams-scam-3.60 enigma2-plugin-softcams-scam-3.59"
RCONFLICTS:${PN} += "enigma2-plugin-softcams-scam-3.60 enigma2-plugin-softcams-scam-3.59"
