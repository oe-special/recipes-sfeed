require ${SOFTCAM_INCLUDES}/oscam-common.inc

inherit cmake

SRC_URI += " \
            file://OSCAM-LICENSE \
            file://init.oscam-generic \
            file://${CAMNAME}/ \
"

LICENSE="GPLv3"
LIC_FILES_CHKSUM = "file://../OSCAM-LICENSE;md5=d32239bcb673463ab874e80d47fae504"

DEPENDS += "libusb openssl"

EXTRA_OECMAKE += "\
	-DWEBIF=1 \
	-DWEBIF_LIVELOG=1 \
	-DWEBIF_JQUERY=1 \
	-DTOUCH=1 \
	-DLCDSUPPORT=1 \
	-DLEDSUPPORT=1 \
	-DWITH_SSL=1 \
	-DWITH_STAPI=0 \
	-DHAVE_LIBUSB=1 \
	-DSTATIC_LIBUSB=0 \
"

do_install () {
	install -d ${D}/${bindir}
	install -m 0755 ${WORKDIR}/build/oscam ${D}/usr/bin/${CAMNAME}
	install -d ${D}/${sysconfdir}/tuxbox/config/${CAMNAME}
	[[ -e ${S}/../${CAMNAME} ]] && install 644 ${S}/../${CAMNAME}/* ${D}/${sysconfdir}/tuxbox/config/${CAMNAME} 2>/dev/null || true
	[[ -e ${D}/${sysconfdir}/tuxbox/config/${CAMNAME}/Sample.configs ]] && rm ${D}/${sysconfdir}/tuxbox/config/${CAMNAME}/Sample.configs 2>/dev/null || true
}

require softcam.inc

