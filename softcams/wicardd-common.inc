PR = "r0"

require softcam-binary.inc
require ${SOFTCAM_INCLUDES}/wicardd-common.inc
require softcam.inc

SRC_URI = " \
            file://wicardd_versions/ \
            file://wicardd.conf \
            file://init.${CAMNAME} \
"

do_install() {
    install -d ${D}/usr/bin
    install -d ${D}/etc/tuxbox/config/${CAMNAME}
    install -m 0755 ${WORKDIR}/wicardd_versions/wicardd_${PV}_${CAM_ARCH} ${D}/usr/bin/${CAMNAME}
    install -m 0755 ${WORKDIR}/wicardd.conf ${D}/etc/tuxbox/config/${CAMNAME}/wicardd.conf
}
