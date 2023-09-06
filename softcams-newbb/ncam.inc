SUMMARY:${PN} = "NCam ${PKGV}"
DESCRIPTION:${PN} = "NCam Open Source Softcam\n \
- latest git revision"

FILESEXTRAPATHS:prepend := "${THISDIR}/../softcams/enigma2-plugin-softcams-ncam:"

CONFFILES:${PN} ?= "/etc/tuxbox/config/${CAMNAME}"

do_configure:prepend () {
	cp ${S}/../init.ncam ${S}/init.${CAMNAME}
}
