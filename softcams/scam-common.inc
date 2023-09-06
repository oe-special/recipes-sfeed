PR = "r0"

SRC_URI = " \
            file://scam_versions/ \
"

require ${SOFTCAM_INCLUDES}/scam-common.inc
require softcam-binary.inc
require softcam.inc

do_install() {
    install -d ${D}/usr/bin
    install -m 0755 ${WORKDIR}/scam_versions/scam_${PV}_${CAM_ARCH} ${D}/usr/bin/${CAMNAME}
}
