PR = "r1-de"

SRC_URI = " \
            file://cccam_versions \
            file://CCcam.cfg \
            file://CCcam.xml \
"

do_install() {
    install -d ${D}/usr/bin
    install -m 0755 ${WORKDIR}/cccam_versions/CCcam_${PV}_${CAM_ARCH} ${D}/usr/bin/${CAMNAME}
    install -d ${D}/etc
    install -m 0755 ${WORKDIR}/CCcam.cfg ${D}/etc/CCcam.cfg
    install -d ${D}/etc/ppanels
    install -m 0644 ${WORKDIR}/CCcam.xml ${D}/etc/ppanels/CCcam.xml
}

require ${SOFTCAM_INCLUDES}/cccam-common.inc
require softcam-binary.inc
require softcam.inc
