# Stuff applying to all doscams on image
SUMMARY = "doscam ${PV} softcam"
LICENSE = "CLOSED"
require conf/license/license-close.inc

require softcam.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/enigma2-plugin-softcams-doscam:"

RDEPENDS_${PN} += "libusb1"

SRC_URI = " \
            file://doscam_${PV}_* \
            file://${CAMNAME}/* \
            file://init.doscam \
"
INHIBIT_PACKAGE_STRIP = "1"

CONFFILES_${PN} ?= "/etc/tuxbox/config/${CAMNAME}"

PACKAGE_ARCH = "${DEFAULTTUNE}"

do_configure_prepend () {
        cp ${WORKDIR}/init.doscam ${S}/init.${CAMNAME}
}

do_install() {
	install -d ${D}/${bindir}
	install -m 0755 ${WORKDIR}/doscam_${PV}_${TARGET_ARCH} ${D}${bindir}/${CAMNAME}
        install -d ${D}/${sysconfdir}/tuxbox/config/${CAMNAME}
        [[ -e ${WORKDIR}/${CAMNAME} ]] && install 777 ${WORKDIR}/${CAMNAME}/* ${D}/${sysconfdir}/tuxbox/config/${CAMNAME} 2>/dev/null || true
        [[ -e ${D}/${sysconfdir}/tuxbox/config/${CAMNAME}/Sample.configs ]] && rm ${D}/${sysconfdir}/tuxbox/config/${CAMNAME}/Sample.configs 2>/dev/null || true
}
