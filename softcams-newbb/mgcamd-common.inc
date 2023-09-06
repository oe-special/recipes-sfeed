SUMMARY:${PN} = "mgcamd ${PKGV}"
DESCRIPTION:${PN} = "An outdated binary only softcam"

FILESEXTRAPATHS:prepend := "${THISDIR}/../softcams/enigma2-plugin-softcams-mgcamd:"

# No aarch64 binary available, use 32 Bit:
CAM_ARCH:aarch64="cortexa15hf-neon-vfpv4"
PACKAGE_ARCH:aarch64="cortexa15hf-neon-vfpv4"

do_compile:prepend() {
    cp ${WORKDIR}/init.${CAMNAME} ${S}/init.${CAMNAME}
}

pkg_postinst:${PN}:prepend () {
	if [ ! -e "$D/lib/ld-linux.so.3" ] && [ -e "$D/lib/ld-linux-armhf.so.3" ]; then
		ln -s ld-linux-armhf.so.3 $D/lib/ld-linux.so.3
	fi
}

RDEPENDS:${PN} = "glibc libcrypto-compat-0.9.7 libgcc zlib"
#RDEPENDS:${PN}:aarch64 = "lib32-glibc lib32-libxcrypt lib32-libcrypto1.0.0 lib32-libgcc lib32-zlib"
RDEPENDS:${PN}:aarch64 = ""
