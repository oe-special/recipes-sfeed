SUMMARY_${PN} = "NCam ${PKGV}"
DESCRIPTION_${PN} = "NCam Open Source Softcam\n \
- latest git revision"

FILESEXTRAPATHS_prepend := "${THISDIR}/../softcams/enigma2-plugin-softcams-ncam:"

CONFFILES_${PN} ?= "/etc/tuxbox/config/${CAMNAME}"

do_configure_prepend () {
	cp ${S}/../init.ncam ${S}/init.${CAMNAME}
}
