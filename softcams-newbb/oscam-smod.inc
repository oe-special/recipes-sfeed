SUMMARY:${PN} = "OSCam-smod ${PKGV}"
DESCRIPTION:${PN} = "Combining the benefits of\n \
- latest trunk\n \
- modern interface\n \
- emu support \
"

do_configure:prepend() {
	mkdir -p ${S}/../${CAMNAME} 2>/dev/null || true
	cp ${F}/SoftCam.Key ${S}/../${CAMNAME}/SoftCam.Key
	[[ -e ${S}/../SoftCam.Key ]] && cp ${S}/../SoftCam.Key ${S}/../${CAMNAME}/SoftCam.Key
	[[ -e ${S}/../const.cw ]] && cp ${S}/../const.cw ${S}/../${CAMNAME}/const.cw
	perl -i -pe 's:Schimmelreiter:oe-alliance:g' ${S}/webif/status/status.html
}

do_compile:prepend() {
	# Shitquake fucks up git revision detection, patch it in
	export GITREV=$(echo ${GITPKGV}) ; sed -i s#CS_SMOD_VERSION\ \ *\"test\"#CS_SMOD_VERSION\ \"${GITREV}\"# ${S}/globals.h
	export GITREVHASH=$(echo ${GITPKGV} | sed s#.*\+##) ; sed -i s#CS_SMOD_VERSION_HASH\ \ *\"\"#CS_SMOD_VERSION_HASH\ \"${GITREVHASH}\"# ${S}/globals.h

	# As we build for a STB, set default for dvbapi to 1 and don't hide idle clients
	perl -i -pe 's:(OFS\(dvbapi_enabled\)[ \t]*?,[ \t]*?)0\),:${1}1\),:g' ${S}/oscam-config-global.c
	perl -i -pe 's:(OFS\(dvbapi_read_sdt\)[ \t]*?,[ \t]*?)0\),:${1}1\),:g' ${S}/oscam-config-global.c
	perl -i -pe 's:(OFS\(http_hide_idle_clients\)[ \t]*?,[ \t]*?)1\),:${1}0\),:g' ${S}/oscam-config-global.c

	#LDFLAGS="${LDFLAGS} -Wl,--format=binary -Wl,SoftCam.Key -Wl,--format=default"
}

RPROVIDES:${PN} += "enigma2-plugin-softcams-oscam-ymod enigma2-plugin-softcams-oscam-atv-ymod enigma2-plugin-softcams-oscam-ymod-openatv"
RREPLACES:${PN} += "enigma2-plugin-softcams-oscam-ymod enigma2-plugin-softcams-oscam-atv-ymod enigma2-plugin-softcams-oscam-ymod-openatv"
RCONFLICTS:${PN} += "enigma2-plugin-softcams-oscam-ymod enigma2-plugin-softcams-oscam-atv-ymod enigma2-plugin-softcams-oscam-ymod-openatv"
