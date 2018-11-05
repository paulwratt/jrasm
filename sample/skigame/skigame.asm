;;;=============================================================================
;;; skigame.asm
;;;=============================================================================
	.org	0x1000
	bios.cls
	ldmw	[score],0
	ldmb	[player.posx],16
loop:
	bios.locate 0,0
	bios.puts "SCORE\0"
	bios.putdec.mb [score],4
	bios.scrolldown 0xc120
	bios.locate 0,1
	bios.filln 0,32
	xrndn.mb 8
	tsta
	bne	nogate
	xrndn.mb 32 - 8
	staa	[gate.posx]
	bios.locate [gate.posx],1
	bios.puts "\x81\x9b\x9b\x9b\x9b\x9b\x9b\x81\0"
nogate:
	.scope
	ldx	0xc100 + 17 * 32
	addx.mb	[player.posx]
	ldaa	[x]
	cmpa	0x9b
	bne	rel1
	inc	[score]
	bra	rel2
rel1:
	cmpa	0x81
	bne	rel2
	dec	[score]
rel2:
	.end

	bios.pick
	cmpa	28
	bne	rel1
	ldaa	[player.posx]
	cmpa	31
	beq	rel2
	inca
	staa	[player.posx]
	bra	rel2
rel1:
	cmpa	29
	bne	rel2
	ldaa	[player.posx]
	cmpa	0
	beq	rel2
	deca
	staa	[player.posx]
rel2:
	bios.locate [player.posx], 17
	bios.putc 'A'
	jmp	loop

	.wseg
score:
	.ds	1
gate.posx:
	.ds	1
player.posx:
	.ds	1

	.include "xrnd.inc"
	.include "bios.inc"
	.include "addsub.inc"
