MAINTAINER = "OpenVisionE2 team"

CAMNAME = "ncam"

require ${SOFTCAM_INCLUDES}/ncam.inc

inherit cmake gitpkgv

SRCREV = "${AUTOREV}"

PV = "git${SRCPV}"
PKGV = "git${GITPKGV}"
PR = "r0"

S = "${WORKDIR}/git"

#SRC_URI="git://github.com/oe-special/NCam.git;protocol=git"
#SRC_URI="git://github.com/OpenVisionE2/NCam.git;protocol=git"
SRC_URI = "git://github.com/fairbird/NCam.git;protocol=https;branch=master \
           file://NCAM-LICENSE \
           file://init.ncam \
           file://${CAMNAME}/ \
          "

LICENSE="GPLv3"
LIC_FILES_CHKSUM = "file://../NCAM-LICENSE;md5=d32239bcb673463ab874e80d47fae504"

DEPENDS += "libusb openssl"

EXTRA_OECMAKE += "\
	-DHAVE_PCSC=0 \
	-DWEBIF=1 \
	-DWEBIF_LIVELOG=1 \
	-DWEBIF_JQUERY=1 \
	-DTOUCH=1 \
	-DWITH_SSL=1 \
	-DWITH_STAPI=0 \
	-DHAVE_LIBUSB=1 \
	-DSTATIC_LIBUSB=0 \
"

do_install () {
	install -d ${D}/${bindir}
	install -m 0755 ${WORKDIR}/build/ncam ${D}/usr/bin/${CAMNAME}
	install -d ${D}/${sysconfdir}/tuxbox/config/${CAMNAME}
	[[ -e ${S}/../${CAMNAME} ]] && install 644 ${S}/../${CAMNAME}/* ${D}/${sysconfdir}/tuxbox/config/${CAMNAME} 2>/dev/null || true
	[[ -e ${D}/${sysconfdir}/tuxbox/config/${CAMNAME}/Sample.configs ]] && rm ${D}/${sysconfdir}/tuxbox/config/${CAMNAME}/Sample.configs 2>/dev/null || true
}

require softcam.inc
