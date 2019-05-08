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

PV = "10.0+git${SRCPV}"
PKGV = "10.0+git${GITPKGV}"

S = "${WORKDIR}/git"
