/* This test case has been created by the Gura script below:
#!/usr/bin/env gura
println('\t.org\t0x1000')

println('\tpcgpage.test.store')

repeat (0x40) {|code|
    code += 0x20
    printf('\tpcg.user%02x.put\n', code)
    printf('\tpcg.user%02x.putattr\n', code)
    printf('\tpcg.user%02x.erase\n', code)
    printf('\tpcg.user%02x.eraseattr\n', code)
}

println('\t.pcgpage test,user:0x20')
repeat (0x40) {|code|
    code += 0x20
    printf('\t.pcg\tuser%02x,1,1\n', code)
    printf('\t.db\t0xff,0xff,0x%02x,0x%02x,0x%02x,0x%02x,0xff,0xff\n', code, code, code, code)
    println('\t.end')
}
println('\t.end')
*/
	.org	0x1000
	pcgpage.test.store
	pcg.user20.put
	pcg.user20.putattr
	pcg.user20.erase
	pcg.user20.eraseattr
	pcg.user21.put
	pcg.user21.putattr
	pcg.user21.erase
	pcg.user21.eraseattr
	pcg.user22.put
	pcg.user22.putattr
	pcg.user22.erase
	pcg.user22.eraseattr
	pcg.user23.put
	pcg.user23.putattr
	pcg.user23.erase
	pcg.user23.eraseattr
	pcg.user24.put
	pcg.user24.putattr
	pcg.user24.erase
	pcg.user24.eraseattr
	pcg.user25.put
	pcg.user25.putattr
	pcg.user25.erase
	pcg.user25.eraseattr
	pcg.user26.put
	pcg.user26.putattr
	pcg.user26.erase
	pcg.user26.eraseattr
	pcg.user27.put
	pcg.user27.putattr
	pcg.user27.erase
	pcg.user27.eraseattr
	pcg.user28.put
	pcg.user28.putattr
	pcg.user28.erase
	pcg.user28.eraseattr
	pcg.user29.put
	pcg.user29.putattr
	pcg.user29.erase
	pcg.user29.eraseattr
	pcg.user2a.put
	pcg.user2a.putattr
	pcg.user2a.erase
	pcg.user2a.eraseattr
	pcg.user2b.put
	pcg.user2b.putattr
	pcg.user2b.erase
	pcg.user2b.eraseattr
	pcg.user2c.put
	pcg.user2c.putattr
	pcg.user2c.erase
	pcg.user2c.eraseattr
	pcg.user2d.put
	pcg.user2d.putattr
	pcg.user2d.erase
	pcg.user2d.eraseattr
	pcg.user2e.put
	pcg.user2e.putattr
	pcg.user2e.erase
	pcg.user2e.eraseattr
	pcg.user2f.put
	pcg.user2f.putattr
	pcg.user2f.erase
	pcg.user2f.eraseattr
	pcg.user30.put
	pcg.user30.putattr
	pcg.user30.erase
	pcg.user30.eraseattr
	pcg.user31.put
	pcg.user31.putattr
	pcg.user31.erase
	pcg.user31.eraseattr
	pcg.user32.put
	pcg.user32.putattr
	pcg.user32.erase
	pcg.user32.eraseattr
	pcg.user33.put
	pcg.user33.putattr
	pcg.user33.erase
	pcg.user33.eraseattr
	pcg.user34.put
	pcg.user34.putattr
	pcg.user34.erase
	pcg.user34.eraseattr
	pcg.user35.put
	pcg.user35.putattr
	pcg.user35.erase
	pcg.user35.eraseattr
	pcg.user36.put
	pcg.user36.putattr
	pcg.user36.erase
	pcg.user36.eraseattr
	pcg.user37.put
	pcg.user37.putattr
	pcg.user37.erase
	pcg.user37.eraseattr
	pcg.user38.put
	pcg.user38.putattr
	pcg.user38.erase
	pcg.user38.eraseattr
	pcg.user39.put
	pcg.user39.putattr
	pcg.user39.erase
	pcg.user39.eraseattr
	pcg.user3a.put
	pcg.user3a.putattr
	pcg.user3a.erase
	pcg.user3a.eraseattr
	pcg.user3b.put
	pcg.user3b.putattr
	pcg.user3b.erase
	pcg.user3b.eraseattr
	pcg.user3c.put
	pcg.user3c.putattr
	pcg.user3c.erase
	pcg.user3c.eraseattr
	pcg.user3d.put
	pcg.user3d.putattr
	pcg.user3d.erase
	pcg.user3d.eraseattr
	pcg.user3e.put
	pcg.user3e.putattr
	pcg.user3e.erase
	pcg.user3e.eraseattr
	pcg.user3f.put
	pcg.user3f.putattr
	pcg.user3f.erase
	pcg.user3f.eraseattr
	pcg.user40.put
	pcg.user40.putattr
	pcg.user40.erase
	pcg.user40.eraseattr
	pcg.user41.put
	pcg.user41.putattr
	pcg.user41.erase
	pcg.user41.eraseattr
	pcg.user42.put
	pcg.user42.putattr
	pcg.user42.erase
	pcg.user42.eraseattr
	pcg.user43.put
	pcg.user43.putattr
	pcg.user43.erase
	pcg.user43.eraseattr
	pcg.user44.put
	pcg.user44.putattr
	pcg.user44.erase
	pcg.user44.eraseattr
	pcg.user45.put
	pcg.user45.putattr
	pcg.user45.erase
	pcg.user45.eraseattr
	pcg.user46.put
	pcg.user46.putattr
	pcg.user46.erase
	pcg.user46.eraseattr
	pcg.user47.put
	pcg.user47.putattr
	pcg.user47.erase
	pcg.user47.eraseattr
	pcg.user48.put
	pcg.user48.putattr
	pcg.user48.erase
	pcg.user48.eraseattr
	pcg.user49.put
	pcg.user49.putattr
	pcg.user49.erase
	pcg.user49.eraseattr
	pcg.user4a.put
	pcg.user4a.putattr
	pcg.user4a.erase
	pcg.user4a.eraseattr
	pcg.user4b.put
	pcg.user4b.putattr
	pcg.user4b.erase
	pcg.user4b.eraseattr
	pcg.user4c.put
	pcg.user4c.putattr
	pcg.user4c.erase
	pcg.user4c.eraseattr
	pcg.user4d.put
	pcg.user4d.putattr
	pcg.user4d.erase
	pcg.user4d.eraseattr
	pcg.user4e.put
	pcg.user4e.putattr
	pcg.user4e.erase
	pcg.user4e.eraseattr
	pcg.user4f.put
	pcg.user4f.putattr
	pcg.user4f.erase
	pcg.user4f.eraseattr
	pcg.user50.put
	pcg.user50.putattr
	pcg.user50.erase
	pcg.user50.eraseattr
	pcg.user51.put
	pcg.user51.putattr
	pcg.user51.erase
	pcg.user51.eraseattr
	pcg.user52.put
	pcg.user52.putattr
	pcg.user52.erase
	pcg.user52.eraseattr
	pcg.user53.put
	pcg.user53.putattr
	pcg.user53.erase
	pcg.user53.eraseattr
	pcg.user54.put
	pcg.user54.putattr
	pcg.user54.erase
	pcg.user54.eraseattr
	pcg.user55.put
	pcg.user55.putattr
	pcg.user55.erase
	pcg.user55.eraseattr
	pcg.user56.put
	pcg.user56.putattr
	pcg.user56.erase
	pcg.user56.eraseattr
	pcg.user57.put
	pcg.user57.putattr
	pcg.user57.erase
	pcg.user57.eraseattr
	pcg.user58.put
	pcg.user58.putattr
	pcg.user58.erase
	pcg.user58.eraseattr
	pcg.user59.put
	pcg.user59.putattr
	pcg.user59.erase
	pcg.user59.eraseattr
	pcg.user5a.put
	pcg.user5a.putattr
	pcg.user5a.erase
	pcg.user5a.eraseattr
	pcg.user5b.put
	pcg.user5b.putattr
	pcg.user5b.erase
	pcg.user5b.eraseattr
	pcg.user5c.put
	pcg.user5c.putattr
	pcg.user5c.erase
	pcg.user5c.eraseattr
	pcg.user5d.put
	pcg.user5d.putattr
	pcg.user5d.erase
	pcg.user5d.eraseattr
	pcg.user5e.put
	pcg.user5e.putattr
	pcg.user5e.erase
	pcg.user5e.eraseattr
	pcg.user5f.put
	pcg.user5f.putattr
	pcg.user5f.erase
	pcg.user5f.eraseattr
	.pcgpage test,user:0x20
	.pcg	user20,1,1
	.db	0xff,0xff,0x20,0x20,0x20,0x20,0xff,0xff
	.end
	.pcg	user21,1,1
	.db	0xff,0xff,0x21,0x21,0x21,0x21,0xff,0xff
	.end
	.pcg	user22,1,1
	.db	0xff,0xff,0x22,0x22,0x22,0x22,0xff,0xff
	.end
	.pcg	user23,1,1
	.db	0xff,0xff,0x23,0x23,0x23,0x23,0xff,0xff
	.end
	.pcg	user24,1,1
	.db	0xff,0xff,0x24,0x24,0x24,0x24,0xff,0xff
	.end
	.pcg	user25,1,1
	.db	0xff,0xff,0x25,0x25,0x25,0x25,0xff,0xff
	.end
	.pcg	user26,1,1
	.db	0xff,0xff,0x26,0x26,0x26,0x26,0xff,0xff
	.end
	.pcg	user27,1,1
	.db	0xff,0xff,0x27,0x27,0x27,0x27,0xff,0xff
	.end
	.pcg	user28,1,1
	.db	0xff,0xff,0x28,0x28,0x28,0x28,0xff,0xff
	.end
	.pcg	user29,1,1
	.db	0xff,0xff,0x29,0x29,0x29,0x29,0xff,0xff
	.end
	.pcg	user2a,1,1
	.db	0xff,0xff,0x2a,0x2a,0x2a,0x2a,0xff,0xff
	.end
	.pcg	user2b,1,1
	.db	0xff,0xff,0x2b,0x2b,0x2b,0x2b,0xff,0xff
	.end
	.pcg	user2c,1,1
	.db	0xff,0xff,0x2c,0x2c,0x2c,0x2c,0xff,0xff
	.end
	.pcg	user2d,1,1
	.db	0xff,0xff,0x2d,0x2d,0x2d,0x2d,0xff,0xff
	.end
	.pcg	user2e,1,1
	.db	0xff,0xff,0x2e,0x2e,0x2e,0x2e,0xff,0xff
	.end
	.pcg	user2f,1,1
	.db	0xff,0xff,0x2f,0x2f,0x2f,0x2f,0xff,0xff
	.end
	.pcg	user30,1,1
	.db	0xff,0xff,0x30,0x30,0x30,0x30,0xff,0xff
	.end
	.pcg	user31,1,1
	.db	0xff,0xff,0x31,0x31,0x31,0x31,0xff,0xff
	.end
	.pcg	user32,1,1
	.db	0xff,0xff,0x32,0x32,0x32,0x32,0xff,0xff
	.end
	.pcg	user33,1,1
	.db	0xff,0xff,0x33,0x33,0x33,0x33,0xff,0xff
	.end
	.pcg	user34,1,1
	.db	0xff,0xff,0x34,0x34,0x34,0x34,0xff,0xff
	.end
	.pcg	user35,1,1
	.db	0xff,0xff,0x35,0x35,0x35,0x35,0xff,0xff
	.end
	.pcg	user36,1,1
	.db	0xff,0xff,0x36,0x36,0x36,0x36,0xff,0xff
	.end
	.pcg	user37,1,1
	.db	0xff,0xff,0x37,0x37,0x37,0x37,0xff,0xff
	.end
	.pcg	user38,1,1
	.db	0xff,0xff,0x38,0x38,0x38,0x38,0xff,0xff
	.end
	.pcg	user39,1,1
	.db	0xff,0xff,0x39,0x39,0x39,0x39,0xff,0xff
	.end
	.pcg	user3a,1,1
	.db	0xff,0xff,0x3a,0x3a,0x3a,0x3a,0xff,0xff
	.end
	.pcg	user3b,1,1
	.db	0xff,0xff,0x3b,0x3b,0x3b,0x3b,0xff,0xff
	.end
	.pcg	user3c,1,1
	.db	0xff,0xff,0x3c,0x3c,0x3c,0x3c,0xff,0xff
	.end
	.pcg	user3d,1,1
	.db	0xff,0xff,0x3d,0x3d,0x3d,0x3d,0xff,0xff
	.end
	.pcg	user3e,1,1
	.db	0xff,0xff,0x3e,0x3e,0x3e,0x3e,0xff,0xff
	.end
	.pcg	user3f,1,1
	.db	0xff,0xff,0x3f,0x3f,0x3f,0x3f,0xff,0xff
	.end
	.pcg	user40,1,1
	.db	0xff,0xff,0x40,0x40,0x40,0x40,0xff,0xff
	.end
	.pcg	user41,1,1
	.db	0xff,0xff,0x41,0x41,0x41,0x41,0xff,0xff
	.end
	.pcg	user42,1,1
	.db	0xff,0xff,0x42,0x42,0x42,0x42,0xff,0xff
	.end
	.pcg	user43,1,1
	.db	0xff,0xff,0x43,0x43,0x43,0x43,0xff,0xff
	.end
	.pcg	user44,1,1
	.db	0xff,0xff,0x44,0x44,0x44,0x44,0xff,0xff
	.end
	.pcg	user45,1,1
	.db	0xff,0xff,0x45,0x45,0x45,0x45,0xff,0xff
	.end
	.pcg	user46,1,1
	.db	0xff,0xff,0x46,0x46,0x46,0x46,0xff,0xff
	.end
	.pcg	user47,1,1
	.db	0xff,0xff,0x47,0x47,0x47,0x47,0xff,0xff
	.end
	.pcg	user48,1,1
	.db	0xff,0xff,0x48,0x48,0x48,0x48,0xff,0xff
	.end
	.pcg	user49,1,1
	.db	0xff,0xff,0x49,0x49,0x49,0x49,0xff,0xff
	.end
	.pcg	user4a,1,1
	.db	0xff,0xff,0x4a,0x4a,0x4a,0x4a,0xff,0xff
	.end
	.pcg	user4b,1,1
	.db	0xff,0xff,0x4b,0x4b,0x4b,0x4b,0xff,0xff
	.end
	.pcg	user4c,1,1
	.db	0xff,0xff,0x4c,0x4c,0x4c,0x4c,0xff,0xff
	.end
	.pcg	user4d,1,1
	.db	0xff,0xff,0x4d,0x4d,0x4d,0x4d,0xff,0xff
	.end
	.pcg	user4e,1,1
	.db	0xff,0xff,0x4e,0x4e,0x4e,0x4e,0xff,0xff
	.end
	.pcg	user4f,1,1
	.db	0xff,0xff,0x4f,0x4f,0x4f,0x4f,0xff,0xff
	.end
	.pcg	user50,1,1
	.db	0xff,0xff,0x50,0x50,0x50,0x50,0xff,0xff
	.end
	.pcg	user51,1,1
	.db	0xff,0xff,0x51,0x51,0x51,0x51,0xff,0xff
	.end
	.pcg	user52,1,1
	.db	0xff,0xff,0x52,0x52,0x52,0x52,0xff,0xff
	.end
	.pcg	user53,1,1
	.db	0xff,0xff,0x53,0x53,0x53,0x53,0xff,0xff
	.end
	.pcg	user54,1,1
	.db	0xff,0xff,0x54,0x54,0x54,0x54,0xff,0xff
	.end
	.pcg	user55,1,1
	.db	0xff,0xff,0x55,0x55,0x55,0x55,0xff,0xff
	.end
	.pcg	user56,1,1
	.db	0xff,0xff,0x56,0x56,0x56,0x56,0xff,0xff
	.end
	.pcg	user57,1,1
	.db	0xff,0xff,0x57,0x57,0x57,0x57,0xff,0xff
	.end
	.pcg	user58,1,1
	.db	0xff,0xff,0x58,0x58,0x58,0x58,0xff,0xff
	.end
	.pcg	user59,1,1
	.db	0xff,0xff,0x59,0x59,0x59,0x59,0xff,0xff
	.end
	.pcg	user5a,1,1
	.db	0xff,0xff,0x5a,0x5a,0x5a,0x5a,0xff,0xff
	.end
	.pcg	user5b,1,1
	.db	0xff,0xff,0x5b,0x5b,0x5b,0x5b,0xff,0xff
	.end
	.pcg	user5c,1,1
	.db	0xff,0xff,0x5c,0x5c,0x5c,0x5c,0xff,0xff
	.end
	.pcg	user5d,1,1
	.db	0xff,0xff,0x5d,0x5d,0x5d,0x5d,0xff,0xff
	.end
	.pcg	user5e,1,1
	.db	0xff,0xff,0x5e,0x5e,0x5e,0x5e,0xff,0xff
	.end
	.pcg	user5f,1,1
	.db	0xff,0xff,0x5f,0x5f,0x5f,0x5f,0xff,0xff
	.end
	.end
