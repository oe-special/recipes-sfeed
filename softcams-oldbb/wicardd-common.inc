SUMMARY_${PN} = "wicardd ${PKGV}"
DESCRIPTION_${PN} = "An outdated binary only softcam"

FILESEXTRAPATHS_prepend := "${THISDIR}/../softcams/enigma2-plugin-softcams-wicardd:"

CONFFILES_${PN} ?= "/etc/tuxbox/config/${CAMNAME}"

# No aarch64 binary available, use 32 Bit:
CAM_ARCH_aarch64="cortexa15hf-neon-vfpv4"
PACKAGE_ARCH_aarch64="cortexa15hf-neon-vfpv4"

do_compile_prepend() {
    cp ${WORKDIR}/init.${CAMNAME} ${S}/init.${CAMNAME}
}

RDEPENDS_${PN} = "glibc libgcc"
RDEPENDS_${PN}_aarch64 = ""
#RDEPENDS_${PN}_aarch64 = "lib32-glibc lib32-libgcc"

RPROVIDES_${PN} += "enigma2-plugin-softcams-wicardd-openatv enigma2-plugin-softcams-wicardd-1.17"
RREPLACES_${PN} += "enigma2-plugin-softcams-wicardd-openatv enigma2-plugin-softcams-wicardd-1.17"
RCONFLICTS_${PN} += "enigma2-plugin-softcams-wicardd-openatv enigma2-plugin-softcams-wicardd-1.17"
