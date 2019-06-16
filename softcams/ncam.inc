MAINTAINER = "fairchild"
SUMMARY_${PN} = "NCam ${PKGV}"
DESCRIPTION_${PN} = "NCam Open Source Softcam\n \
- latest git revision"

#SRC_URI="git://github.com/oe-special/NCam.git;protocol=git"
SRC_URI="git://github.com/fairbird/NCam.git;protocol=git"

CAMNAME = "ncam"

EXTRA_OECMAKE += "\
	-DHAVE_PCSC=0 \
"

require ncam-common.inc

inherit gitpkgv

SRCREV = "${AUTOREV}"

PV = "10.1+git${SRCPV}"
PKGV = "10.1+git${GITPKGV}"

S = "${WORKDIR}/git"
