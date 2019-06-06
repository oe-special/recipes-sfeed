MAINTAINER = "oscam-emu"
SUMMARY = "OScam - Open Source Softcam - oscam-emu ${PV}"
DESCRIPTION = "with emu support\n"

SRC_URI="git://github.com/oscam-emu/oscam-patched.git;protocol=git"

CAMNAME = "oscam-emu"

EXTRA_OECMAKE += "\
	-DHAVE_PCSC=0 \
"

require oscam-common.inc

inherit gitpkgv

SRCREV = "${AUTOREV}"

PV = "1.20+git${SRCPV}"
PKGV = "1.20+git${GITPKGV}"

S = "${WORKDIR}/git"

RPROVIDES_${PN} += "enigma2-plugin-softcams-oscam-atv-emu"
RREPLACES_${PN} += "enigma2-plugin-softcams-oscam-atv-emu"
RCONFLICTS_${PN} += "enigma2-plugin-softcams-oscam-atv-emu"
