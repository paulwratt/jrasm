	.org	0x1000
	;; ------------------------
	lda		a,0x12
	lda		a,{0x12}
	lda		a,[x]
	lda		a,[x+0x12]
	lda		a,[x+0x12+0x34]
	lda		a,[0x12+x]
	lda		a,[0x12+0x34+x]
	lda		a,[0x34+x+0x12]
	lda		a,[0x1234]
	;; ------------------------
	ldaa	0x12
	ldaa	{0x12}
	ldaa	[x]
	ldaa	[x+0x12]
	ldaa	[x+0x12+0x34]
	ldaa	[0x12+x]
	ldaa	[0x12+0x34+x]
	ldaa	[0x34+x+0x12]
	ldaa	[0x1234]
	;; ------------------------
	sta		a,{0x00}
	sta		a,[x]
	sta		a,[x+0x12]
	sta		a,[x+0x12+0x34]
	sta		a,[0x12+x]
	sta		a,[0x12+0x34+x]
	sta		a,[0x34+x+0x12]
	sta		a,[0x1234]
	;; ------------------------
	staa	{0x00}
	staa	[x]
	staa	[x+0x12]
	staa	[x+0x12+0x34]
	staa	[0x12+x]
	staa	[0x12+0x34+x]
	staa	[0x34+x+0x12]
	staa	[0x1234]
	;; ------------------------
	jmp		x
	jmp		x+0x12
	jmp		0x1234
