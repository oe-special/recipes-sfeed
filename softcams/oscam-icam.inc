CAMNAME = "oscam-icam"

#           file://sogno_unibox_dvbapi-11518_boxtype_sogno_version.patch 

SRCREV = "11718"
SRC_URI = "svn://svn.streamboard.tv/oscam;protocol=https;module=trunk;scmdata=keep;rev=${SRCREV};externals=nowarn \
           file://oscam-emu.patch \
           file://oscam_emu_icam_dvbapi_radegast_v9.patch \
          "
EXTRA_OECMAKE += "\
	-DHAVE_PCSC=0 \
	-DWITH_SOFTCAM=0 \
	-DWITH_SSL=0 \
	-DTOUCH=0 \
	-DWITH_LCD_SUPPORT=0 \
	-DWITH_LED_SUPPORT=0 \
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
