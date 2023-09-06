SUMMARY_${PN} = "mgcamd ${PKGV}"
DESCRIPTION_${PN} = "An outdated binary only softcam"

FILESEXTRAPATHS_prepend := "${THISDIR}/../softcams/enigma2-plugin-softcams-mgcamd:"

# No aarch64 binary available, use 32 Bit:
CAM_ARCH_aarch64="cortexa15hf-neon-vfpv4"
PACKAGE_ARCH_aarch64="cortexa15hf-neon-vfpv4"

do_compile_prepend() {
    cp ${WORKDIR}/init.${CAMNAME} ${S}/init.${CAMNAME}
}

pkg_postinst_${PN}_prepend () {
	if [ ! -e "$D/lib/ld-linux.so.3" ] && [ -e "$D/lib/ld-linux-armhf.so.3" ]; then
		ln -s ld-linux-armhf.so.3 $D/lib/ld-linux.so.3
	fi
}

RDEPENDS_${PN} = "libgcc zlib"
RDEPENDS_${PN}_aarch64 = ""
#RDEPENDS_${PN}_aarch64 = "lib32-libxcrypt lib32-libcrypto1.0.0 lib32-libgcc lib32-zlib"
