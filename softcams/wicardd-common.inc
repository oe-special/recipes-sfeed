# Stuff applying to all wicardd on image
SUMMARY_${PN} = "wicardd ${PKGV}"
DESCRIPTION_${PN} = "An outdated binary only softcam"

PR = "r0"

LICENSE = "CLOSED"
require conf/license/license-close.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/enigma2-plugin-softcams-wicardd:"

SRC_URI = " \
            file://wicardd_versions/ \
            file://wicardd.conf \
            file://init.${CAMNAME} \
"

require softcam.inc
require softcam-binary-32bit.inc

CONFFILES_${PN} ?= "/etc/tuxbox/config/${CAMNAME}"

PACKAGE_ARCH = "${DEFAULTTUNE}"
CAM_ARCH="arm"
CAM_ARCH_mipsel="mipsel"
CAM_ARCH_sh4="sh4"

do_compile_prepend() {
    cp ${WORKDIR}/init.${CAMNAME} ${S}/init.${CAMNAME}
}

do_install() {
    install -d ${D}/usr/bin
    install -d ${D}/etc/tuxbox/config/${CAMNAME}
    install -m 0755 ${WORKDIR}/wicardd_versions/wicardd_${PV}_${CAM_ARCH} ${D}/usr/bin/${CAMNAME}
    install -m 0755 ${WORKDIR}/wicardd.conf ${D}/etc/tuxbox/config/${CAMNAME}/wicardd.conf
}

RDEPENDS_${PN}_aarch64 = "lib32-glibc lib32-libgcc softcam-support"

INHIBIT_PACKAGE_STRIP = "1"
INSANE_SKIP_${PN} = "already-stripped build-deps ldflags"
INSANE_SKIP_${PN}_aarch64 = "already-stripped arch build-deps ldflags file-rdeps"

RPROVIDES_${PN} += "enigma2-plugin-softcams-wicardd-openatv enigma2-plugin-softcams-wicardd-1.17"
RREPLACES_${PN} += "enigma2-plugin-softcams-wicardd-openatv enigma2-plugin-softcams-wicardd-1.17"
RCONFLICTS_${PN} += "enigma2-plugin-softcams-wicardd-openatv enigma2-plugin-softcams-wicardd-1.17"
