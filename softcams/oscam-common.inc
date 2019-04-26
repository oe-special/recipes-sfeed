# Stuff applying to all oscams on image

require softcam.inc
inherit cmake

FILESEXTRAPATHS_prepend := "${THISDIR}/enigma2-plugin-softcams-oscam:"

SRC_URI += " \
            file://OSCAM-LICENSE \
            file://init.oscam-generic \
"

LICENSE="GPLv3"
LIC_FILES_CHKSUM = "file://OSCAM-LICENSE;md5=d32239bcb673463ab874e80d47fae504"

CONFFILES_${PN} ?= "/etc/tuxbox/config/${CAMNAME}"

PACKAGE_ARCH = "${DEFAULTTUNE}"

DEPENDS = "libusb openssl"

EXTRA_OECMAKE += "\
	-DWEBIF=1 \
	-DWEBIF_LIVELOG=1 \
	-DWEBIF_JQUERY=1 \
	-DTOUCH=1 \
	-DWITH_SSL=1 \
	-DWITH_STAPI=0 \
	-DHAVE_LIBUSB=1 \
	-DSTATIC_LIBUSB=0 \
"

do_compile_prepend () {
	install -m 755 ${S}/init.oscam-generic ${S}/init.${CAMNAME}
}

do_install_prepend () {
    install -d ${D}/${bindir}
    install -m 0755 ${WORKDIR}/build/oscam ${D}/usr/bin/${CAMNAME}
    install -d ${D}/${sysconfdir}/tuxbox/config/${CAMNAME}
}
