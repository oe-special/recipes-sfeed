# Stuff applying to all mgcamd on image
SUMMARY_${PN} = "mgcamd ${PKGV}"
DESCRIPTION_${PN} = "An outdated binary only softcam"

PR="r4.0"

LICENSE = "CLOSED"
require conf/license/license-close.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/enigma2-plugin-softcams-mgcamd:"

SRC_URI = " \
            file://mgcamd_versions/ \
            file://init.mgcamd \
"

require softcam.inc
require softcam-binary-32bit.inc

#CONFFILES_${PN} ?= "/etc/CCcam.cfg"

PACKAGE_ARCH = "${DEFAULTTUNE}"
CAM_ARCH="arm"
CAM_ARCH_mipsel="mips32el"
CAM_ARCH_sh4="sh4"

do_compile_prepend() {
    cp ${WORKDIR}/init.${CAMNAME} ${S}/init.${CAMNAME}
}

do_install() {
    cp ${S}/../init.mgcamd ${S}/init.mgcamd
    install -d ${D}/usr/bin
    install -m 0755 ${S}/../mgcamd_versions/mgcamd_${PV}_${CAM_ARCH} ${D}/usr/bin/${CAMNAME}
}

pkg_postinst_${PN}_prepend () {
	if [ ! -e "$D/lib/ld-linux.so.3" ] && [ -e "$D/lib/ld-linux-armhf.so.3" ]; then
		ln -s ld-linux-armhf.so.3 $D/lib/ld-linux.so.3
	fi
}

RDEPENDS_${PN}_aarch64 = "lib32-glibc lib32-libxcrypt lib32-libcrypto1.0.0 lib32-libgcc lib32-zlib softcam-support"

do_prepare_recipe_sysroot[noexec] = "1"
INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
deltask do_populate_sysroot
INSANE_SKIP_${PN} += "already-stripped arch build-deps ldflags file-rdeps"
