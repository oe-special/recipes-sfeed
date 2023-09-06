SUMMARY:${PN} = "wicardd ${PKGV}"
DESCRIPTION:${PN} = "An outdated binary only softcam"

FILESEXTRAPATHS:prepend := "${THISDIR}/../softcams/enigma2-plugin-softcams-wicardd:"

CONFFILES:${PN} ?= "/etc/tuxbox/config/${CAMNAME}"

# No aarch64 binary available, use 32 Bit:
CAM_ARCH:aarch64="cortexa15hf-neon-vfpv4"
PACKAGE_ARCH:aarch64="cortexa15hf-neon-vfpv4"

do_compile:prepend() {
    cp ${WORKDIR}/init.${CAMNAME} ${S}/init.${CAMNAME}
}

RDEPENDS:${PN} = "glibc libgcc"
RDEPENDS:${PN}:aarch64 = ""
#RDEPENDS:${PN}:aarch64 = "lib32-glibc lib32-libgcc"

RPROVIDES:${PN} += "enigma2-plugin-softcams-wicardd-openatv enigma2-plugin-softcams-wicardd-1.17"
RREPLACES:${PN} += "enigma2-plugin-softcams-wicardd-openatv enigma2-plugin-softcams-wicardd-1.17"
RCONFLICTS:${PN} += "enigma2-plugin-softcams-wicardd-openatv enigma2-plugin-softcams-wicardd-1.17"
