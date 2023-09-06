MAINTAINER = "oscam-emu"
CAMNAME = "oscam-emu"

inherit gitpkgv

SRCREV = "${AUTOREV}"

PV = "1.20+git${SRCPV}"
PKGV = "1.20+git${GITPKGV}"
#PR = "r0"

S = "${WORKDIR}/git"

SRC_URI="git://github.com/oscam-emu/oscam-patched.git;protocol=https;branch=master"

require oscam-common.inc

EXTRA_OECMAKE += "\
	-DHAVE_PCSC=0 \
"

require ${SOFTCAM_INCLUDES}/oscam-emu.inc

