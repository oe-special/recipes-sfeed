SUMMARY = "meta file for enigma2 softcam packages"

require conf/license/license-gplv2.inc

PROVIDES = "openatv-softcams"

DEPENDS = "enigma2-plugin-extensions-oscamsmartcard"

SOFTCAMS = "\
	enigma2-plugin-softcams-oscam-smod \
	enigma2-plugin-softcams-oscam-smod-ipv4only \
	enigma2-plugin-softcams-oscam-emu \
	enigma2-plugin-softcams-oscam-emu-ipv4only \
	enigma2-plugin-softcams-oscam-trunk \
	enigma2-plugin-softcams-oscam-trunk-ipv4only \
	enigma2-plugin-softcams-oscam-stable \
	enigma2-plugin-softcams-oscam-stable-ipv4only \
	enigma2-plugin-softcams-oscam-icam \
	enigma2-plugin-softcams-oscam-icam-ipv4only \
	enigma2-plugin-softcams-ncam \
	enigma2-plugin-softcams-ncam-ipv4only \
	${@bb.utils.contains("DEFAULTTUNE", "sh4", " ${SOFTCAM_BINARY}" , "", d)} \
	${@bb.utils.contains("TARGET_ARCH", "mipsel", " ${SOFTCAM_BINARY}" , "", d)} \
	${@bb.utils.contains("DEFAULTTUNE", "armv7ahf-neon", " ${SOFTCAM_BINARY}" , "", d)} \
	${@bb.utils.contains("DEFAULTTUNE", "cortexa7hf", " ${SOFTCAM_BINARY}" , "", d)} \
	${@bb.utils.contains("DEFAULTTUNE", "cortexa7hf-vfp", " ${SOFTCAM_BINARY}" , "", d)} \
	${@bb.utils.contains("DEFAULTTUNE", "cortexa9hf-neon", " ${SOFTCAM_BINARY}" , "", d)} \
	${@bb.utils.contains("DEFAULTTUNE", "cortexa15hf-neon-vfpv4", " ${SOFTCAM_BINARY}" , "", d)} \
	${@bb.utils.contains('TARGET_ARCH', 'aarch64', " ${SOFTCAM_BINARY}" , "", d)} \
"


SOFTCAM_BINARY = "\
	${@bb.utils.contains("DEFAULTTUNE", "cortexa7hf", "", "enigma2-plugin-softcams-gbox", d)} \
	${@bb.utils.contains("DEFAULTTUNE", "cortexa7hf", "", "enigma2-plugin-softcams-wicardd", d)} \
	${@bb.utils.contains("DEFAULTTUNE", "cortexa7hf", "", "enigma2-plugin-softcams-mgcamd", d)} \
	\
	${@bb.utils.contains("DEFAULTTUNE", "sh4", "enigma2-plugin-softcams-cccam", "", d)} \
	${@bb.utils.contains("TARGET_ARCH", "mipsel", "enigma2-plugin-softcams-cccam", "", d)} \
	${@bb.utils.contains("TARGET_ARCH", "aarch64", "enigma2-plugin-softcams-cccam", "", d)} \
	${@bb.utils.contains("DEFAULTTUNE", "armv7ahf-neon", "enigma2-plugin-softcams-cccam", "", d)} \
	${@bb.utils.contains("DEFAULTTUNE", "cortexa7hf", "enigma2-plugin-softcams-cccam", "", d)} \
	${@bb.utils.contains("DEFAULTTUNE", "cortexa7hf-vfp", "enigma2-plugin-softcams-cccam", "", d)} \
	${@bb.utils.contains("DEFAULTTUNE", "cortexa9hf-neon", "enigma2-plugin-softcams-cccam", "", d)} \
	${@bb.utils.contains("DEFAULTTUNE", "cortexa15hf-neon-vfpv4", "enigma2-plugin-softcams-cccam" , "", d)} \
	\
	${@bb.utils.contains("TARGET_ARCH", "mipsel", "enigma2-plugin-softcams-doscam", "", d)} \
	${@bb.utils.contains("TARGET_ARCH", "aarch64", "enigma2-plugin-softcams-doscam", "", d)} \
	${@bb.utils.contains("DEFAULTTUNE", "armv7ahf-neon", "enigma2-plugin-softcams-doscam", "", d)} \
	${@bb.utils.contains("DEFAULTTUNE", "cortexa9hf-neon", "enigma2-plugin-softcams-doscam", "", d)} \
	${@bb.utils.contains("DEFAULTTUNE", "cortexa15hf-neon-vfpv4", "enigma2-plugin-softcams-doscam" , "", d)} \
	\
	${@bb.utils.contains("TARGET_ARCH", "mipsel", "enigma2-plugin-softcams-scam", "", d)} \
	"

DEPENDS += "\
	${SOFTCAMS} \
"

PR = "r0"
