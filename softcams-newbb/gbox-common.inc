SUMMARY:${PN} = "gbox.net ${PKGV}"
DESCRIPTION:${PN} = "A binary only softcam"

FILESEXTRAPATHS:prepend := "${THISDIR}/../softcams/enigma2-plugin-softcams-gbox:"

FILES:${PN} += "/var/keys /tmp"
CONFFILES:${PN} = "/var/keys"

# No aarch64 binary available, use 32 Bit:
CAM_ARCH:aarch64="cortexa15hf-neon-vfpv4"
PACKAGE_ARCH:aarch64="cortexa15hf-neon-vfpv4"

pkg_postinst:${PN}:prepend () {
	if [ -e "$D/tmp/libnxp.so" ] && [ ! -e "$D/lib/libnxp.so" ] && [ ! -e "$D/usr/lib/libnxp.so" ]; then
		mv $D/tmp/libnxp.so $D/usr/lib/libnxp.so 2>/dev/null
	fi
	if [ ! -e "$D/lib/ld-linux.so.3" ] && [ -e "$D/lib/ld-linux-armhf.so.3" ]; then
		ln -s ld-linux-armhf.so.3 $D/lib/ld-linux.so.3
	fi
}

RDEPENDS:${PN} = "glibc libgcc"
RDEPENDS:${PN}:aarch64 = ""
#RDEPENDS:${PN}:aarch64 = "lib32-glibc lib32-libgcc"
