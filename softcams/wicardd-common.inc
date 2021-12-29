# Stuff applying to all wicardd on image
SUMMARY:${PN} = "wicardd ${PKGV}"
DESCRIPTION:${PN} = "An outdated binary only softcam"

PR = "r0"

LICENSE = "CLOSED"
require conf/license/license-close.inc

FILESEXTRAPATHS:prepend := "${THISDIR}/enigma2-plugin-softcams-wicardd:"

SRC_URI = " \
            file://wicardd_versions/ \
            file://wicardd.conf \
            file://init.${CAMNAME} \
"

require softcam.inc
require softcam-binary-32bit.inc

CONFFILES:${PN} ?= "/etc/tuxbox/config/${CAMNAME}"

CAM_ARCH="arm"
CAM_ARCH:mipsel="mipsel"
CAM_ARCH:sh4="sh4"

do_compile:prepend() {
    cp ${WORKDIR}/init.${CAMNAME} ${S}/init.${CAMNAME}
}

do_install() {
    install -d ${D}/usr/bin
    install -d ${D}/etc/tuxbox/config/${CAMNAME}
    install -m 0755 ${WORKDIR}/wicardd_versions/wicardd_${PV}_${CAM_ARCH} ${D}/usr/bin/${CAMNAME}
    install -m 0755 ${WORKDIR}/wicardd.conf ${D}/etc/tuxbox/config/${CAMNAME}/wicardd.conf
}

RDEPENDS:${PN}:aarch64 = "lib32-glibc lib32-libgcc softcam-support"

do_prepare_recipe_sysroot[noexec] = "1"
INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
deltask do_populate_sysroot
INSANE_SKIP:${PN} = "already-stripped build-deps ldflags"
INSANE_SKIP:${PN}:aarch64 = "already-stripped arch build-deps ldflags file-rdeps"

RPROVIDES:${PN} += "enigma2-plugin-softcams-wicardd-openatv enigma2-plugin-softcams-wicardd-1.17"
RREPLACES:${PN} += "enigma2-plugin-softcams-wicardd-openatv enigma2-plugin-softcams-wicardd-1.17"
RCONFLICTS:${PN} += "enigma2-plugin-softcams-wicardd-openatv enigma2-plugin-softcams-wicardd-1.17"
