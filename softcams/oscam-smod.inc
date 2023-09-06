MAINTAINER = "smod"
CAMNAME = "oscam-smod"

inherit gitpkgv

SRCREV = "${AUTOREV}"

SMODSVN := ""

PV = "1.20+git${SRCPV}"
PKGV = "1.20+git${GITPKGV}"
PR = "r0"

S = "${WORKDIR}/git"
F = "${WORKDIR}/git/files"

SRC_URI="git://github.com/Schimmelreiter/oscam-smod.git;protocol=https;branch=master"

require oscam-common.inc

require ${SOFTCAM_INCLUDES}/oscam-smod.inc

EXTRA_OECMAKE += "\
	-DWITH_NEUTRINO=1 \
	-DHAVE_PCSC=0 \
        -DCS_ANTICASC=1 \
        -DCS_CACHEEX=1 \
        -DCS_CACHEEX_AIO=1 \
        -DCW_CYCLE_CHECK=1 \
        -DCARDREADER_MP35=1 \
        -DCARDREADER_SC8IN1=1 \
        -DCARDREADER_SMARGO=1 \
        -DMODULE_SERIAL=1 \
        -DMODULE_CONSTCW=1 \
        -DMODULE_PANDORA=1 \
        -DMODULE_GHTTP=1 \
"

python do_get_smodsvn () {
    src = d.getVar('S')
    f = open(src + "/.trunk-svn", "r")
    d.setVar('SMODSVN',f.readline())
}

#addtask get_smodsvn after do_unpack before do_patch
