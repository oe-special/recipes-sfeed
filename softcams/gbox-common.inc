PR = "r4.2"

SRC_URI = " \
            file://gbox_versions/ \
            file://init.gbox \
            \
            file://libnxp.so.arm \
            \
            file://conax \
            file://constcw \
            file://crypto \
            file://cwshare.cfg \
            file://cwshare.rules \
            file://drecrypt \
            file://gbox.cfg \
            file://gbox.pmc \
            file://ignore.list \
            file://irdeto \
            file://nagra \
            file://nds \
            file://powervu \
            file://seca \
            file://softcam.cfg \
            file://via \
"

do_install() {
    cp ${S}/../init.gbox ${S}/init.${CAMNAME}

    install -d ${D}/usr/bin
    install -m 0755 ${WORKDIR}/gbox_versions/gbox_${PV}_${CAM_ARCH} ${D}/usr/bin/${CAMNAME}
    if [ "x${CAM_ARCH}" == "xarm" ]; then
        install -d ${D}/tmp
        install -m 0755 ${WORKDIR}/libnxp.so.arm ${D}/tmp/libnxp.so
    fi
    install -d ${D}/var/keys
    for CFG in conax constcw crypto cwshare.cfg cwshare.rules drecrypt gbox.cfg gbox.pmc ignore.list irdeto nagra nds powervu seca softcam.cfg via
    do
        install -m 0755 ${WORKDIR}/$CFG ${D}/var/keys
    done

}

require softcam-binary.inc
require ${SOFTCAM_INCLUDES}/gbox-common.inc
require softcam.inc
