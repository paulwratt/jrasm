        .ORG    0x1000

        PCGPAGE.page1.STORE
        LDX     0xc100+16+10*32
        PCG.circle2x2.PUT
        LDX     0xc500+16+10*32
        PCG.circle2x2.PUTATTR 5,0
        RTS

        .PCGPAGE page1,CRAM:0x80

        .PCG    circle2x2,2,2
        .DB     b".....######....."
        .DB     b"...##......##..."
        .DB     b"..#..........#.."
        .DB     b".#............#."
        .DB     b".#............#."
        .DB     b"#..............#"
        .DB     b"#..............#"
        .DB     b"#..............#"
        .DB     b"#..............#"
        .DB     b"#..............#"
        .DB     b"#..............#"
        .DB     b".#............#."
        .DB     b".#............#."
        .DB     b"..#..........#.."
        .DB     b"...##......##..."
        .DB     b".....######....."
        .END

	.pcg	circle1x1,1,1
	.db	b"..####.."
	.db	b".#....#."
	.db	b"#......#"
	.db	b"#......#"
	.db	b"#......#"
	.db	b"#......#"
	.db	b".#....#."
	.db	b"..####.."
	.end

	.pcg	dblcircle1x1,1,1
	.db	b"..####.."
	.db	b".#....#."
	.db	b"#..##..#"
	.db	b"#.#..#.#"
	.db	b"#.#..#.#"
	.db	b"#..##..#"
	.db	b".#....#."
	.db	b"..####.."
	.end
	
	.pcg	circle2x2,2,2
	.db	b".....######....."
	.db	b"...##......##..."
	.db	b"..#..........#.."
	.db	b".#............#."
	.db	b".#............#."
	.db	b"#..............#"
	.db	b"#..............#"
	.db	b"#..............#"
	.db	b"#..............#"
	.db	b"#..............#"
	.db	b"#..............#"
	.db	b".#............#."
	.db	b".#............#."
	.db	b"..#..........#.."
	.db	b"...##......##..."
	.db	b".....######....."
	.end

	.pcg	blank2x1,2,1
	.db	b"................"
	.db	b"................"
	.db	b"................"
	.db	b"................"
	.db	b"................"
	.db	b"................"
	.db	b"................"
	.db	b"................"
	.end
	
	.pcg	chkcircle2x2,2,2
	.db	b".....######....."
	.db	b"...##...#####..."
	.db	b"..#.....######.."
	.db	b".#......#######."
	.db	b".#......#######."
	.db	b"#.......########"
	.db	b"#.......########"
	.db	b"#.......########"
	.db	b"########.......#"
	.db	b"########.......#"
	.db	b"########.......#"
	.db	b".#######......#."
	.db	b".#######......#."
	.db	b"..######.....#.."
	.db	b"...#####...##..."
	.db	b".....######....."
	.end

        .END