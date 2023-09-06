PR = "r1"

SRC_URI = " \
            file://doscam_versions/ \
            file://${CAMNAME}/ \
            file://init.doscam \
"

do_install() {
	install -d ${D}/${bindir}
	install -m 0755 ${WORKDIR}/doscam_versions/doscam_${PV}_${CAM_ARCH} ${D}${bindir}/${CAMNAME}
        install -d ${D}/${sysconfdir}/tuxbox/config/${CAMNAME}
        [[ -e ${WORKDIR}/${CAMNAME} ]] && install 777 ${WORKDIR}/${CAMNAME}/* ${D}/${sysconfdir}/tuxbox/config/${CAMNAME} 2>/dev/null || true
        [[ -e ${D}/${sysconfdir}/tuxbox/config/${CAMNAME}/Sample.configs ]] && rm ${D}/${sysconfdir}/tuxbox/config/${CAMNAME}/Sample.configs 2>/dev/null || true
}

require ${SOFTCAM_INCLUDES}/doscam-common.inc
require softcam-binary.inc
require softcam.inc

