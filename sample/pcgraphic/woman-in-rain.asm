	; makeasm.gura -l 50 -h 60 woman-in-rain.jpg
	.org	0x1000

	pcgpage.page.store
	ldx	0xc100
	pcg.screen.putx
	ldx	0xc500
	pcg.screen.putattrx
infinite:
	bra	infinite
	
	.pcgpage page,cram:1,user:32
	.pcg	screen,32,24
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0xbf,0xff,0xaf,0xff,0xff,0xfa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xbf,0xfa,0xab,0xff,0xff,0xea,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xfe,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaf,0xea,0xab,0xff,0xff,0xea,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xab,0xff
	.db	0xfe,0xbe,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0x8a,0xaf,0xff,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xaa,0xab,0xff
	.db	0xaa,0xfe,0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xea,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0x82,0xbf,0xff,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe
	.db	0xff,0xff,0xff,0xa0,0x0a,0xbf,0xff,0xff,0xff,0xff,0xff,0xaa,0xaa,0xaa,0xab,0xff
	.db	0xab,0xff,0xea,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xa0,0x02,0xab,0xff,0xff,0xff,0xff,0xff,0xaa,0xff,0xff,0xff,0xff
	.db	0xaa,0xbe,0xa2,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xaa,0x00,0x00,0x0a,0xff,0xff,0xff,0xff,0xff,0xaa,0xaa,0xaa,0xab,0xff
	.db	0xab,0xff,0xfa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xab,0xa0,0x00,0x2a,0xff,0xff,0xff,0xff,0xff,0xea,0xaf,0xff,0xff,0xff
	.db	0x2a,0xbf,0xea,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xff,0xff,0xff
	.db	0xbf,0xff,0x02,0x80,0x00,0x02,0xff,0xff,0xfb,0xff,0xff,0xe0,0xaa,0xaa,0xab,0xff
	.db	0xab,0xff,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xfe,0xaa,0xaa,0x00,0x2a,0xff,0xff,0xff,0xff,0xff,0xfe,0xaf,0xff,0xff,0xff
	.db	0xaa,0xbf,0xfa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xfe,0x0a,0x00,0x00,0x02,0xbf,0xfe,0xff,0xff,0xff,0xfa,0xaa,0xfe,0xab,0xff
	.db	0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xfa,0x2a,0x80,0xaa,0x02,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xbf,0xfa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xef,0xf8,0x00,0x00,0x00,0x00,0xaf,0xab,0xff,0xff,0xff,0xff,0xaf,0xfe,0xaa,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xf0,0x20,0x00,0x0a,0x80,0x2a,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xea,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfb,0xe0,0x00,0x00,0x00,0x00,0x0a,0xbf,0xff,0xff,0xff,0xfb,0xff,0xfe,0xab,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xe0,0x80,0x00,0x02,0xa0,0x0b,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xc0,0x00,0x00,0x00,0x00,0x02,0xfb,0xff,0xff,0xff,0xff,0xbf,0xfe,0xbb,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0x80,0x00,0x00,0x00,0x02,0x03,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xff
	.db	0xfe,0x80,0x00,0x00,0x00,0x00,0x02,0xff,0xff,0xff,0xff,0xff,0xfb,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0x20,0x00,0x00,0x00,0x00,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xbf
	.db	0xfe,0x00,0x00,0x00,0x00,0x00,0x02,0xbf,0xff,0xbf,0xff,0xff,0xfe,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0x20,0x00,0x02,0x00,0x00,0x0a,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb
	.db	0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0xbe,0xbf,0xbf,0xff,0xff,0xff,0xef,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0xa0,0x00,0x0a,0xa0,0x00,0x00,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x2b,0xaa,0xff,0xff,0xff,0xff,0xfe,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0x2a,0x00,0x0a,0xb8,0x00,0x00,0x0b,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf8,0x00,0x00,0x00,0xa8,0x00,0x00,0x02,0xfb,0xef,0xff,0xff,0xff,0xff,0xaf,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0x2a,0xa0,0x2a,0xbf,0x80,0x00,0x02,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf8,0x08,0x00,0x00,0xae,0x00,0x00,0x00,0xbf,0xff,0xff,0xff,0xff,0xff,0xfa,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfa,0xff,0xff,0xff
	.db	0xf8,0x2a,0xa0,0x0a,0xaf,0xe0,0x00,0x00,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xaa,0xaa,0xaa
	.db	0xa8,0x28,0x00,0x00,0xaf,0xe0,0x00,0x00,0x2f,0xff,0xff,0xff,0xff,0xff,0xff,0xbf
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf8,0x2e,0xa0,0x00,0xaf,0xfe,0x00,0x08,0x2f,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xaa,0xff,0xff,0xff
	.db	0xf8,0x28,0x00,0x00,0xab,0xf8,0x00,0x00,0x0a,0xff,0xff,0xff,0xfe,0xaa,0xff,0xef
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf8,0xbe,0xa0,0x00,0xab,0xff,0x83,0xff,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xfa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xea,0xab,0xff,0xff
	.db	0xf0,0x28,0x00,0x00,0x2b,0xfe,0x82,0xfa,0xe2,0xff,0xff,0xff,0xbe,0xba,0xbf,0xfe
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf0,0xbe,0x80,0x00,0x2b,0xff,0xe0,0xbf,0xfa,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xea,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfa,0xeb,0xff,0xfe
	.db	0xe0,0xba,0x00,0x00,0x02,0xff,0x80,0xbf,0xf0,0xbf,0xff,0xef,0xfa,0xea,0xaf,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xe0,0xbe,0x80,0x00,0x0a,0xff,0xf0,0x3f,0xfe,0xbf,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xfb,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb
	.db	0xe0,0xba,0x00,0x00,0x00,0xbf,0xe0,0x3f,0xfc,0x2f,0xff,0xfb,0xfe,0xff,0xaf,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xe0,0xbf,0x00,0x00,0x02,0xff,0xf8,0x3f,0xfe,0x3f,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xaa,0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xa0,0xbe,0x00,0x00,0x00,0xbf,0xe0,0x3f,0xfe,0x2f,0xff,0xef,0xfe,0xff,0xef,0xff
	.db	0xff,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf0,0xbe,0x00,0x02,0x80,0xbf,0xf8,0xbf,0xfe,0xaf,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0xaa,0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe
	.db	0xa0,0x3e,0x00,0x00,0x00,0x2f,0xf8,0x3f,0xfe,0x0b,0xff,0xff,0xff,0xef,0xef,0xff
	.db	0xfe,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf0,0x3f,0xe0,0xaa,0x80,0x2f,0xf8,0xff,0xfa,0x8f,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xbf,0xff,0xff,0xff,0xff,0xff,0xfe
	.db	0xa0,0x3f,0xa0,0x0a,0x00,0x2f,0xf8,0xbf,0xfa,0x8a,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xb0,0x3f,0xff,0xff,0xab,0xff,0xf8,0xff,0xf2,0x8f,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe
	.db	0xa0,0x3f,0xaa,0xfa,0xaa,0xaf,0xf8,0xff,0xf2,0x8a,0xbf,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xfa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf8,0x3c,0x8b,0xff,0xff,0xff,0xfb,0xff,0xf2,0x8f,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe
	.db	0xa0,0x28,0x02,0xff,0xbf,0xff,0xfb,0xff,0xf2,0x8a,0xaf,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xfa,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf8,0x2e,0xff,0xff,0xff,0xff,0xff,0xff,0xf3,0x8f,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfa
	.db	0xe0,0x2a,0xab,0xff,0xff,0xff,0xff,0xff,0xf2,0x8a,0xbf,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf8,0x2f,0xff,0xff,0xff,0xff,0xff,0xff,0xf3,0xcf,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb
	.db	0xf8,0x2f,0xff,0xff,0xff,0xff,0xff,0xff,0xf2,0x8a,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfc,0x2f,0xff,0xff,0xff,0xff,0xff,0xff,0xc3,0xcf,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb
	.db	0xf8,0x2f,0xff,0xff,0xff,0xff,0xff,0xff,0xc2,0x8b,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfc,0x2f,0xff,0xff,0xff,0xff,0xff,0xff,0x83,0xcf,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0x00,0xaa,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf8,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0x82,0x8b,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfc,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0x03,0xaf,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0x00,0x2a,0xaa,0xa2,0xbf,0xff,0xff,0xff,0xff,0xef,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfc,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0x02,0x8b,0xff,0xff,0xbf,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0x0b,0xff,0xff,0xff,0xff,0xff,0xfe,0x0b,0xaf,0xff,0xff,0xef,0xff,0xff,0xff
	.db	0x00,0x00,0x22,0xaa,0xbf,0xff,0xff,0xff,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfc,0x0b,0xff,0xfe,0xff,0xff,0xff,0xfc,0x02,0x2b,0xff,0xfe,0xaf,0xff,0xff,0xfe
	.db	0xaa,0xaa,0xaa,0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0x03,0xff,0xff,0xff,0xff,0xff,0xfc,0x0a,0x3f,0xff,0xff,0xfb,0xff,0xff,0xfe
	.db	0x00,0x00,0x02,0xaa,0xbf,0xff,0xff,0xfa,0xbf,0xeb,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfc,0x03,0xff,0xab,0xfe,0xff,0xff,0xfc,0x02,0x2a,0xff,0xfa,0xab,0xff,0xff,0xfa
	.db	0xaa,0xaa,0xaa,0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0x02,0xff,0xff,0xfe,0xff,0xff,0xfc,0x08,0xbf,0xff,0xff,0xfe,0xff,0xff,0xfa
	.db	0x00,0x02,0xaa,0xaa,0xaf,0xff,0xff,0xea,0xbf,0xea,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfc,0x00,0xff,0xff,0xfa,0xff,0xff,0xf8,0x00,0x2a,0xaa,0xaa,0xaa,0xff,0xff,0xf8
	.db	0xaa,0xaa,0xaa,0xaa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0x00,0xbf,0xff,0xbf,0xff,0xff,0xf8,0x0a,0xbf,0xff,0xff,0xff,0xbf,0xff,0xfe
	.db	0x00,0x02,0xaa,0xaa,0xaf,0xff,0xff,0xff,0xff,0xab,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfc,0x00,0xbe,0xfa,0xab,0xff,0xff,0xf0,0x00,0xaa,0xaa,0xaa,0xaa,0xbf,0xff,0xfa
	.db	0xaa,0xaa,0xaa,0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0x00,0x3f,0xef,0xff,0xff,0xff,0xf0,0x0a,0xff,0xff,0xff,0xff,0xff,0xff,0xfe
	.db	0x00,0x00,0xaa,0xaa,0xaf,0xff,0xff,0xff,0xea,0xaa,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfc,0x00,0x2e,0xaa,0xaf,0xff,0xff,0xf0,0x02,0xaa,0xaa,0xaa,0xaa,0xaf,0xff,0xfa
	.db	0x2a,0xaa,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0x00,0x0b,0xff,0xff,0xff,0xff,0xe0,0x0a,0xff,0xff,0xff,0xff,0xfb,0xff,0xfe
	.db	0x00,0x00,0x0a,0xaa,0xaf,0xff,0xff,0xff,0xea,0xaa,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfc,0x00,0x0a,0xea,0xbf,0xff,0xff,0xe0,0x02,0xaa,0xaa,0xaa,0xaa,0xab,0xff,0xfa
	.db	0x2a,0xaa,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0x00,0x02,0xff,0xff,0xff,0xff,0xc0,0x2a,0xff,0xff,0xff,0xff,0xfa,0xff,0xfe
	.db	0x00,0x00,0x0a,0xaa,0xab,0xff,0xff,0xff,0xfa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfc,0x00,0x00,0xbf,0xff,0xff,0xff,0xc0,0x02,0xaa,0xaa,0xaa,0xaa,0xaa,0xff,0xfa
	.db	0xaa,0xaa,0xaa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0x00,0x00,0x3f,0xff,0xff,0xff,0xc0,0x0a,0xff,0xff,0xff,0xff,0xfe,0xff,0xfa
	.db	0x00,0x00,0x0a,0xaa,0xab,0xff,0xff,0xff,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfc,0x00,0x00,0x2f,0xff,0xff,0xff,0x80,0x02,0xba,0xaa,0xaa,0xaa,0xaa,0xbf,0xf8
	.db	0xaa,0xaa,0xaa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0x00,0x00,0x0b,0xff,0xff,0xff,0xc0,0x0a,0xff,0xfb,0xff,0xff,0xea,0xbf,0xfa
	.db	0x0a,0x02,0xaa,0xaa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfc,0x00,0x00,0x0b,0xff,0xff,0xff,0x80,0x02,0xaa,0xaa,0xaa,0xaa,0xaa,0xaf,0xf8
	.db	0xaa,0xaa,0xaa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0x00,0x00,0x0f,0xff,0xff,0xff,0x0a,0x0a,0xff,0xff,0xff,0xff,0xfa,0xaf,0xfa
	.db	0xaa,0x0a,0xaa,0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf8,0x00,0x00,0x0b,0xff,0xff,0xfe,0x02,0x02,0xae,0xaa,0xaa,0xaa,0xaa,0xab,0xf8
	.db	0xfa,0xab,0xea,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfc,0x00,0x00,0x3f,0xff,0xff,0xfc,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xfa
	.db	0xaa,0x0a,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf8,0x00,0x00,0x2f,0xff,0xff,0xf8,0x0b,0xef,0xaf,0xea,0xae,0xaa,0xaa,0xaa,0xfa
	.db	0xfe,0xab,0xfa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf8,0x00,0x00,0xbf,0xff,0xff,0xf0,0x2b,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xff
	.db	0xea,0xaa,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf8,0x00,0x00,0x3f,0xff,0xff,0xf0,0x0b,0xff,0xff,0xfa,0xbe,0xaa,0xaa,0xaa,0xba
	.db	0xfe,0xab,0xfa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfa,0x00,0x00,0xff,0xff,0xff,0xe0,0x2f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xbf
	.db	0xfa,0xaa,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf2,0x00,0x00,0xff,0xff,0xff,0xe0,0x0b,0xff,0xff,0xfb,0xfe,0xae,0xaa,0xba,0xba
	.db	0xfe,0xab,0xfa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf3,0x00,0x03,0xff,0xff,0xff,0xe0,0x2f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfa,0xaa,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf3,0x00,0x03,0xff,0xff,0xff,0xe0,0x2f,0xff,0xff,0xff,0xfe,0xbf,0xff,0xef,0xaa
	.db	0xff,0xab,0xea,0xaf,0xff,0xff,0xff,0xff,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf3,0x80,0x0b,0xff,0xff,0xff,0xe0,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0xaa,0xaa,0xaa,0xff,0xff,0xff,0xfe,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xf3,0x00,0x03,0xff,0xff,0xff,0xc0,0x3f,0xff,0xff,0xff,0xea,0xff,0xff,0xfa,0xaa
	.db	0xff,0xab,0xea,0xaf,0xff,0xff,0xff,0xff,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfb,0x80,0x0f,0xff,0xff,0xff,0xc2,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0xaa,0xa8,0xaa,0xff,0xff,0xff,0xff,0x8b,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xe3,0x00,0x0f,0xff,0xff,0xff,0xc0,0xff,0xff,0xff,0xff,0xeb,0xbe,0xaf,0xaa,0xaa
	.db	0xff,0xab,0xea,0xaf,0xff,0xff,0xff,0xff,0xea,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfb,0x80,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfa,0xaa,0xa8,0xaa,0xbf,0xff,0xff,0xff,0x8a,0xbf,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xe3,0x80,0x2f,0xff,0xff,0xff,0xef,0xff,0xff,0xff,0xff,0xff,0xeb,0xfa,0xaa,0xaa
	.db	0xfa,0xab,0xfa,0xaf,0xff,0xff,0xff,0xff,0xea,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xeb,0x80,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xea,0xaa,0xea,0xaa,0xbf,0xff,0xff,0xff,0xaa,0xab,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xe2,0x80,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xaa,0xaa
	.db	0xea,0xaf,0xfe,0xab,0xff,0xff,0xff,0xff,0xea,0xba,0xbf,0xff,0xff,0xff,0xff,0xff
	.db	0xea,0x00,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xab,0xfa,0xaa,0xbf,0xff,0xff,0xff,0xea,0xaa,0xbf,0xff,0xff,0xff,0xff,0xff
	.db	0xca,0x00,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfa,0xaa,0xaa,0xaa
	.db	0xea,0xaf,0xff,0xea,0xff,0xff,0xff,0xff,0xea,0xaa,0xaf,0xff,0xff,0xff,0xff,0xff
	.db	0xc8,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xa8,0x2b,0xfa,0xaa,0xbf,0xff,0xff,0xff,0xea,0xaa,0x0b,0xff,0xff,0xff,0xff,0xff
	.db	0xc0,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xaa,0xaa,0xaa,0xaa
	.db	0xfa,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xfa,0xaa,0xab,0xff,0xff,0xff,0xff,0xff
	.db	0x80,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xe8,0x2a,0xfa,0xaa,0xbf,0xff,0xff,0xff,0xea,0xa8,0x0a,0xff,0xff,0xff,0xff,0xff
	.db	0x80,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xea,0xaa,0xaa,0xaa,0xaa
	.db	0xfa,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xaa,0xab,0xff,0xff,0xff,0xff,0xf8
	.db	0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xe8,0x0a,0xfa,0xab,0xff,0xff,0xff,0xff,0xfa,0xa8,0x0a,0xff,0xff,0xfb,0xff,0xf8
	.db	0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xea,0xaa,0xaa,0xaa,0xaa
	.db	0xfa,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xab,0xff,0xff,0xff,0xff,0xc0
	.db	0x80,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfa,0x0a,0xfa,0xaf,0xff,0xff,0xff,0xff,0xfa,0xa8,0x0a,0xbf,0xff,0xff,0xff,0x80
	.db	0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xea,0xaa,0xaa,0xaa,0xaa
	.db	0xfe,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xab,0xff,0xff,0xff,0xfe,0x02
	.db	0x80,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfa,0x02,0xfa,0xaf,0xff,0xff,0xff,0xff,0xfa,0xaa,0xaa,0xaa,0xaf,0xff,0xfe,0x00
	.db	0x00,0x00,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xaa,0xaa,0xaa,0xaa
	.db	0xfe,0xaa,0xfe,0xbf,0xff,0xff,0xff,0xff,0xff,0xea,0xbf,0xff,0xff,0xff,0xfc,0x00
	.db	0x80,0x00,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfa,0x8a,0xaa,0xab,0xff,0xff,0xff,0xff,0xfe,0xaa,0xaa,0xaa,0xeb,0xff,0xf8,0x00
	.db	0x00,0x00,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xaa,0xaa,0xaa,0xaa
	.db	0xff,0xaa,0xfa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x20
	.db	0x00,0xa0,0x2f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0xaa,0xaa,0xaa,0xff,0xff,0xff,0xff,0xfe,0xaa,0xaa,0xaf,0xfe,0xff,0xf8,0x00
	.db	0x00,0x00,0x2f,0xea,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xaa,0xaa,0xaa,0xaa
	.db	0xff,0xfb,0xea,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfa,0x20
	.db	0x02,0x02,0x8b,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfe,0xaa,0xaa,0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xe0,0x00
	.db	0x00,0x00,0x0b,0xaa,0xaa,0xab,0xff,0xff,0xff,0xff,0xfe,0xaa,0xaa,0xaa,0xaa,0xaa
	.db	0xff,0xff,0xfa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0xaa
	.db	0x00,0x82,0x8b,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xaa,0xaa,0xaa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x00
	.db	0x00,0x00,0x02,0xea,0xaa,0xaa,0xbf,0xff,0xff,0xff,0xfe,0xaa,0xaa,0xbf,0xaa,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf2,0x2a
	.db	0x02,0xaa,0x8b,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xea,0xaa,0xaa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x00
	.db	0x00,0x02,0x0a,0xfe,0xaa,0xaa,0xab,0xff,0xff,0xff,0xfa,0xaa,0xab,0xff,0xaa,0xfe
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0x28
	.db	0x02,0xab,0x8f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xfa,0xaa,0xaa,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe2,0x00
	.db	0x00,0xaa,0x0b,0xfe,0xaa,0xaa,0xaa,0xab,0xff,0xff,0xfa,0xaa,0xaf,0xfe,0xae,0xfe
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfa,0x02
	.db	0xa2,0xef,0xaf,0xff,0xff,0xbf,0xff,0xff,0xff,0xff,0xff,0xfb,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xab,0xfe,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe2,0x00
	.db	0x00,0xaa,0x0f,0xfa,0xfa,0xaa,0xaa,0xaa,0xaa,0xaf,0xfa,0xaa,0xaf,0xfe,0xab,0xfa
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x82
	.db	0xe2,0xef,0xff,0xff,0xfe,0xaa,0xaa,0xaa,0xff,0xff,0xfa,0xaa,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xab,0xff,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe8,0x00
	.db	0xe0,0xab,0xbf,0xeb,0xfa,0xaa,0xaa,0x02,0xaa,0xaf,0xea,0xaa,0xaa,0xaa,0xaf,0xea
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfa
	.db	0xe2,0xef,0xff,0xff,0xff,0xab,0xeb,0xaa,0xbf,0xff,0xea,0xab,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xae,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xee,0xf8
	.db	0xe2,0xaf,0xff,0xff,0xea,0xaa,0xaa,0x88,0xaa,0xaf,0xe0,0xaa,0xaa,0xaa,0xfe,0xaa
	.db	0xff,0xea,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xe2,0xef,0xff,0xff,0xff,0xff,0xff,0xeb,0xbf,0xff,0xea,0xaf,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xaa,0xaa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe
	.db	0xe2,0xaf,0xff,0xff,0xea,0xaa,0xaa,0xaa,0xaa,0xbf,0xea,0xaa,0xaa,0xff,0xff,0xff
	.db	0xff,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xe2,0xbf,0xff,0xff,0xff,0xff,0xff,0xfb,0xeb,0xff,0xea,0xbf,0xff,0xff,0xff,0xff
	.db	0xaa,0xa0,0xaa,0xaa,0xaa,0xab,0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xa0,0x2f,0xff,0xff,0xea,0xaa,0xaa,0xaa,0xaa,0xbf,0xaa,0xaa,0xaf,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xbf,0xea,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xa0,0x3f,0xff,0xff,0xff,0xff,0xff,0xfe,0xff,0xff,0xbe,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xa0,0x0a,0xaa,0xaa,0xaa,0xaa,0xaf,0xfe,0xbf,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xa0,0x3f,0xff,0xff,0xfe,0xaa,0xff,0xba,0xaa,0xaf,0xaa,0xaf,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xab,0xea,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xa0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xbf,0xff,0xff,0xff,0xff,0xff
	.db	0xa0,0x00,0x0a,0xaa,0xaa,0xaa,0xaa,0xaa,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xa0,0x3f,0xff,0xff,0xff,0xff,0xff,0xfe,0xba,0xbe,0xaa,0xaf,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xaa,0xaa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0x00,0x0a,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xe0,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xaf,0xa8,0xaa,0xbf,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xff,0xaa,0xaa,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0x00,0x0a,0xaa,0xaa,0xa0,0xaa,0xaa,0xaa,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xe2,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xeb,0xf8,0xfa,0xbf,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xff,0xea,0xaa,0xaa,0xaa,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0x0a,0xaa,0xaa,0xaa,0x80,0x2a,0xaa,0xaa,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xea,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xfa,0xfa,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xbf,0xaf,0xaa,0xaa,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0x0a,0xaa,0xaa,0xaa,0x80,0x00,0x00,0xaa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xaa,0xa0,0xaa,0x0a,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0x0a,0xaa,0xaa,0xaa,0x80,0x00,0x00,0x2a,0xbf,0xff,0xff,0xff,0xff,0xef,0xff,0xff
	.db	0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0x2a,0xaa,0xaa,0xaa,0xa0,0x2a,0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0x02,0x00,0x02,0xa0,0x00,0x00,0x0a,0xab,0xff,0xff,0xff,0xff,0xff,0xef,0xff,0xff
	.db	0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0x0a,0x80,0x02,0xaa,0xaa,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0x00,0x00,0x00,0x00,0x00,0x2a,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xff,0xaf
	.db	0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb
	.db	0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0x00,0x00,0x0a,0xaa,0xaa,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xfe,0xaa
	.db	0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xff,0xfb
	.db	0xeb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xaa,0xaa,0xaa,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xff,0xaa
	.db	0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xff,0xef
	.db	0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xeb,0xff,0xaa
	.db	0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xff,0xee
	.db	0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xeb,0xff,0xaa
	.db	0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xff,0xee
	.db	0xbe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfa,0xfe,0xaa
	.db	0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xbf,0xfa
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfa,0xbe,0xaa
	.db	0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xbb
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xaa,0xaa
	.db	0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xeb
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xea,0xaa
	.db	0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xab
	.db	0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xaf
	.db	0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.db	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	.end
	.end