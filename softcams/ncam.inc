MAINTAINER = "fairchild"
SUMMARY = "Ncam - Open Source Softcam ${PV}"

SRC_URI="git://github.com/oe-special/NCam.git;protocol=git"

CAMNAME = "ncam"

EXTRA_OECMAKE += "\
	-DHAVE_PCSC=0 \
"

require ncam-common.inc

inherit gitpkgv

SRCREV = "${AUTOREV}"

PV = "9.7+git${SRCPV}"
PKGV = "9.7+git${GITPKGV}"

S = "${WORKDIR}/git"
