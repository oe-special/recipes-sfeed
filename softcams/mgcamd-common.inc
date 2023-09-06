PR="r4.0"

SRC_URI = " \
            file://mgcamd_versions/ \
            file://init.mgcamd \
"

do_install() {
    cp ${S}/../init.mgcamd ${S}/init.mgcamd
    install -d ${D}/usr/bin
    install -m 0755 ${S}/../mgcamd_versions/mgcamd_${PV}_${CAM_ARCH} ${D}/usr/bin/${CAMNAME}
}

require softcam-binary.inc
require ${SOFTCAM_INCLUDES}/mgcamd-common.inc
require softcam.inc

