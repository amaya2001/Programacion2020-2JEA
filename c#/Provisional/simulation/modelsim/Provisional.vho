-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 13.0.0 Build 156 04/24/2013 SJ Web Edition"

-- DATE "12/02/2020 11:04:14"

-- 
-- Device: Altera EP2C20F484C7 Package FBGA484
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEII;
LIBRARY IEEE;
USE CYCLONEII.CYCLONEII_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	procesoCuatro IS
    PORT (
	finalizacionP2 : OUT std_logic;
	CLK : IN std_logic;
	userNext : IN std_logic;
	seleccion : IN std_logic;
	YA : OUT std_logic;
	ALGO : OUT std_logic
	);
END procesoCuatro;

-- Design Ports Information
-- finalizacionP2	=>  Location: PIN_R20,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- YA	=>  Location: PIN_U19,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- ALGO	=>  Location: PIN_R19,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- userNext	=>  Location: PIN_R22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- CLK	=>  Location: PIN_D12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- seleccion	=>  Location: PIN_M22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default


ARCHITECTURE structure OF procesoCuatro IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_finalizacionP2 : std_logic;
SIGNAL ww_CLK : std_logic;
SIGNAL ww_userNext : std_logic;
SIGNAL ww_seleccion : std_logic;
SIGNAL ww_YA : std_logic;
SIGNAL ww_ALGO : std_logic;
SIGNAL \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~clkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \CLK~clkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \seleccion~clkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita0~combout\ : std_logic;
SIGNAL \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita3~COUT\ : std_logic;
SIGNAL \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita4~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita0~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita1~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita2~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita3~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita3~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita4~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita4~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita5~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita5~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita6~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita6~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita7~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita7~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita8~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita8~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita9~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita9~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita10~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita10~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita11~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita11~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita12~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita12~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita13~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita13~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita14~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita14~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita15~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita15~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita16~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita16~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita17~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita17~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita18~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita18~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita19~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita19~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita20~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita20~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita21~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita21~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita22~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita22~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita23~combout\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita23~COUT\ : std_logic;
SIGNAL \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita24~combout\ : std_logic;
SIGNAL \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~0_combout\ : std_logic;
SIGNAL \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~1_combout\ : std_logic;
SIGNAL \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~2_combout\ : std_logic;
SIGNAL \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~3_combout\ : std_logic;
SIGNAL \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~4_combout\ : std_logic;
SIGNAL \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~5_combout\ : std_logic;
SIGNAL \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~6_combout\ : std_logic;
SIGNAL \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~clkctrl_outclk\ : std_logic;
SIGNAL \CLK~combout\ : std_logic;
SIGNAL \CLK~clkctrl_outclk\ : std_logic;
SIGNAL \userNext~combout\ : std_logic;
SIGNAL \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\ : std_logic;
SIGNAL \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita1~combout\ : std_logic;
SIGNAL \seleccion~combout\ : std_logic;
SIGNAL \seleccion~clkctrl_outclk\ : std_logic;
SIGNAL \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\ : std_logic;
SIGNAL \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\ : std_logic;
SIGNAL \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita3~combout\ : std_logic;
SIGNAL \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita2~combout\ : std_logic;
SIGNAL \inst7~0_combout\ : std_logic;
SIGNAL \inst7~1_combout\ : std_logic;
SIGNAL \inst7~regout\ : std_logic;
SIGNAL \inst3~0_combout\ : std_logic;
SIGNAL \inst5~regout\ : std_logic;
SIGNAL \inst4|LPM_COUNTER_component|auto_generated|safe_q\ : std_logic_vector(4 DOWNTO 0);
SIGNAL \inst|LPM_COUNTER_component|auto_generated|safe_q\ : std_logic_vector(24 DOWNTO 0);
SIGNAL \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire\ : std_logic_vector(0 DOWNTO 0);
SIGNAL \ALT_INV_seleccion~clkctrl_outclk\ : std_logic;

BEGIN

finalizacionP2 <= ww_finalizacionP2;
ww_CLK <= CLK;
ww_userNext <= userNext;
ww_seleccion <= seleccion;
YA <= ww_YA;
ALGO <= ww_ALGO;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~clkctrl_INCLK_bus\ <= (gnd & gnd & gnd & \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire\(0));

\CLK~clkctrl_INCLK_bus\ <= (gnd & gnd & gnd & \CLK~combout\);

\seleccion~clkctrl_INCLK_bus\ <= (gnd & gnd & gnd & \seleccion~combout\);
\ALT_INV_seleccion~clkctrl_outclk\ <= NOT \seleccion~clkctrl_outclk\;

-- Location: LCFF_X49_Y10_N25
\inst4|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[4]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~clkctrl_outclk\,
	datain => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita4~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst4|LPM_COUNTER_component|auto_generated|safe_q\(4));

-- Location: LCFF_X49_Y10_N17
\inst4|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[0]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~clkctrl_outclk\,
	datain => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita0~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst4|LPM_COUNTER_component|auto_generated|safe_q\(0));

-- Location: LCCOMB_X49_Y10_N16
\inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita0\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita0~combout\ = \inst4|LPM_COUNTER_component|auto_generated|safe_q\(0) $ (VCC)
-- \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\ = CARRY(\inst4|LPM_COUNTER_component|auto_generated|safe_q\(0))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010110101010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \inst4|LPM_COUNTER_component|auto_generated|safe_q\(0),
	datad => VCC,
	combout => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita0~combout\,
	cout => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\);

-- Location: LCCOMB_X49_Y10_N22
\inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita3\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita3~combout\ = (\inst4|LPM_COUNTER_component|auto_generated|safe_q\(3) & (!\inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\)) # 
-- (!\inst4|LPM_COUNTER_component|auto_generated|safe_q\(3) & ((\inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\) # (GND)))
-- \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita3~COUT\ = CARRY((!\inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\) # (!\inst4|LPM_COUNTER_component|auto_generated|safe_q\(3)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst4|LPM_COUNTER_component|auto_generated|safe_q\(3),
	datad => VCC,
	cin => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\,
	combout => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita3~combout\,
	cout => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita3~COUT\);

-- Location: LCCOMB_X49_Y10_N24
\inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita4\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita4~combout\ = \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita3~COUT\ $ (!\inst4|LPM_COUNTER_component|auto_generated|safe_q\(4))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000001111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datad => \inst4|LPM_COUNTER_component|auto_generated|safe_q\(4),
	cin => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita3~COUT\,
	combout => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita4~combout\);

-- Location: LCFF_X24_Y25_N21
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[22]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita22~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(22));

-- Location: LCFF_X24_Y25_N19
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[21]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita21~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(21));

-- Location: LCFF_X24_Y25_N25
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[24]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita24~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(24));

-- Location: LCFF_X24_Y25_N23
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[23]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita23~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(23));

-- Location: LCFF_X24_Y25_N13
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[18]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita18~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(18));

-- Location: LCFF_X24_Y25_N17
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[20]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita20~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(20));

-- Location: LCFF_X24_Y25_N15
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[19]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita19~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(19));

-- Location: LCFF_X24_Y25_N11
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[17]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita17~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(17));

-- Location: LCFF_X24_Y25_N9
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[16]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita16~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(16));

-- Location: LCFF_X24_Y25_N7
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[15]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita15~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(15));

-- Location: LCFF_X24_Y25_N5
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[14]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita14~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(14));

-- Location: LCFF_X24_Y25_N3
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[13]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita13~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(13));

-- Location: LCFF_X24_Y26_N27
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[9]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita9~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(9));

-- Location: LCFF_X24_Y25_N1
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[12]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita12~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(12));

-- Location: LCFF_X24_Y26_N31
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[11]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita11~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(11));

-- Location: LCFF_X24_Y26_N29
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[10]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita10~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(10));

-- Location: LCFF_X24_Y26_N25
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[8]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita8~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(8));

-- Location: LCFF_X24_Y26_N19
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[5]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita5~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(5));

-- Location: LCFF_X24_Y26_N23
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[7]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita7~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(7));

-- Location: LCFF_X24_Y26_N21
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[6]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita6~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(6));

-- Location: LCFF_X24_Y26_N9
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[0]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~clkctrl_outclk\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita0~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(0));

-- Location: LCFF_X24_Y26_N17
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[4]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita4~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(4));

-- Location: LCFF_X24_Y26_N15
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[3]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita3~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(3));

-- Location: LCFF_X24_Y26_N13
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[2]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita2~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(2));

-- Location: LCFF_X24_Y26_N11
\inst|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[1]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~combout\,
	datain => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita1~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst|LPM_COUNTER_component|auto_generated|safe_q\(1));

-- Location: LCCOMB_X24_Y26_N8
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita0\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita0~combout\ = \inst|LPM_COUNTER_component|auto_generated|safe_q\(0) $ (VCC)
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\ = CARRY(\inst|LPM_COUNTER_component|auto_generated|safe_q\(0))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001111001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(0),
	datad => VCC,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita0~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\);

-- Location: LCCOMB_X24_Y26_N10
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita1\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita1~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(1) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\)) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(1) & ((\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\) # (GND)))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\ = CARRY((!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(1)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(1),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita1~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\);

-- Location: LCCOMB_X24_Y26_N12
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita2\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita2~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(2) & (\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\ $ (GND))) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(2) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\ & VCC))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\ = CARRY((\inst|LPM_COUNTER_component|auto_generated|safe_q\(2) & !\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(2),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita2~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\);

-- Location: LCCOMB_X24_Y26_N14
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita3\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita3~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(3) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\)) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(3) & ((\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\) # (GND)))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita3~COUT\ = CARRY((!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(3)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(3),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita3~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita3~COUT\);

-- Location: LCCOMB_X24_Y26_N16
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita4\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita4~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(4) & (\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita3~COUT\ $ (GND))) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(4) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita3~COUT\ & VCC))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita4~COUT\ = CARRY((\inst|LPM_COUNTER_component|auto_generated|safe_q\(4) & !\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita3~COUT\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(4),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita3~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita4~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita4~COUT\);

-- Location: LCCOMB_X24_Y26_N18
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita5\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita5~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(5) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita4~COUT\)) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(5) & ((\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita4~COUT\) # (GND)))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita5~COUT\ = CARRY((!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita4~COUT\) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(5)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(5),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita4~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita5~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita5~COUT\);

-- Location: LCCOMB_X24_Y26_N20
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita6\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita6~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(6) & (\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita5~COUT\ $ (GND))) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(6) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita5~COUT\ & VCC))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita6~COUT\ = CARRY((\inst|LPM_COUNTER_component|auto_generated|safe_q\(6) & !\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita5~COUT\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(6),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita5~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita6~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita6~COUT\);

-- Location: LCCOMB_X24_Y26_N22
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita7\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita7~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(7) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita6~COUT\)) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(7) & ((\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita6~COUT\) # (GND)))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita7~COUT\ = CARRY((!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita6~COUT\) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(7)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(7),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita6~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita7~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita7~COUT\);

-- Location: LCCOMB_X24_Y26_N24
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita8\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita8~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(8) & (\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita7~COUT\ $ (GND))) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(8) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita7~COUT\ & VCC))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita8~COUT\ = CARRY((\inst|LPM_COUNTER_component|auto_generated|safe_q\(8) & !\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita7~COUT\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(8),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita7~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita8~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita8~COUT\);

-- Location: LCCOMB_X24_Y26_N26
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita9\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita9~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(9) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita8~COUT\)) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(9) & ((\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita8~COUT\) # (GND)))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita9~COUT\ = CARRY((!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita8~COUT\) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(9)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(9),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita8~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita9~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita9~COUT\);

-- Location: LCCOMB_X24_Y26_N28
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita10\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita10~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(10) & (\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita9~COUT\ $ (GND))) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(10) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita9~COUT\ & VCC))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita10~COUT\ = CARRY((\inst|LPM_COUNTER_component|auto_generated|safe_q\(10) & !\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita9~COUT\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(10),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita9~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita10~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita10~COUT\);

-- Location: LCCOMB_X24_Y26_N30
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita11\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita11~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(11) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita10~COUT\)) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(11) & ((\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita10~COUT\) # (GND)))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita11~COUT\ = CARRY((!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita10~COUT\) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(11)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(11),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita10~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita11~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita11~COUT\);

-- Location: LCCOMB_X24_Y25_N0
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita12\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita12~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(12) & (\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita11~COUT\ $ (GND))) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(12) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita11~COUT\ & VCC))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita12~COUT\ = CARRY((\inst|LPM_COUNTER_component|auto_generated|safe_q\(12) & !\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita11~COUT\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(12),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita11~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita12~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita12~COUT\);

-- Location: LCCOMB_X24_Y25_N2
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita13\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita13~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(13) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita12~COUT\)) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(13) & ((\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita12~COUT\) # (GND)))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita13~COUT\ = CARRY((!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita12~COUT\) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(13)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(13),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita12~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita13~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita13~COUT\);

-- Location: LCCOMB_X24_Y25_N4
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita14\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita14~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(14) & (\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita13~COUT\ $ (GND))) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(14) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita13~COUT\ & VCC))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita14~COUT\ = CARRY((\inst|LPM_COUNTER_component|auto_generated|safe_q\(14) & !\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita13~COUT\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(14),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita13~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita14~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita14~COUT\);

-- Location: LCCOMB_X24_Y25_N6
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita15\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita15~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(15) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita14~COUT\)) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(15) & ((\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita14~COUT\) # (GND)))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita15~COUT\ = CARRY((!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita14~COUT\) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(15)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(15),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita14~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita15~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita15~COUT\);

-- Location: LCCOMB_X24_Y25_N8
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita16\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita16~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(16) & (\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita15~COUT\ $ (GND))) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(16) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita15~COUT\ & VCC))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita16~COUT\ = CARRY((\inst|LPM_COUNTER_component|auto_generated|safe_q\(16) & !\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita15~COUT\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(16),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita15~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita16~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita16~COUT\);

-- Location: LCCOMB_X24_Y25_N10
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita17\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita17~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(17) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita16~COUT\)) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(17) & ((\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita16~COUT\) # (GND)))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita17~COUT\ = CARRY((!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita16~COUT\) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(17)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(17),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita16~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita17~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita17~COUT\);

-- Location: LCCOMB_X24_Y25_N12
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita18\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita18~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(18) & (\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita17~COUT\ $ (GND))) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(18) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita17~COUT\ & VCC))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita18~COUT\ = CARRY((\inst|LPM_COUNTER_component|auto_generated|safe_q\(18) & !\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita17~COUT\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(18),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita17~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita18~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita18~COUT\);

-- Location: LCCOMB_X24_Y25_N14
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita19\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita19~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(19) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita18~COUT\)) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(19) & ((\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita18~COUT\) # (GND)))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita19~COUT\ = CARRY((!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita18~COUT\) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(19)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(19),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita18~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita19~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita19~COUT\);

-- Location: LCCOMB_X24_Y25_N16
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita20\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita20~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(20) & (\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita19~COUT\ $ (GND))) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(20) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita19~COUT\ & VCC))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita20~COUT\ = CARRY((\inst|LPM_COUNTER_component|auto_generated|safe_q\(20) & !\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita19~COUT\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(20),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita19~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita20~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita20~COUT\);

-- Location: LCCOMB_X24_Y25_N18
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita21\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita21~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(21) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita20~COUT\)) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(21) & ((\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita20~COUT\) # (GND)))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita21~COUT\ = CARRY((!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita20~COUT\) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(21)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(21),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita20~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita21~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita21~COUT\);

-- Location: LCCOMB_X24_Y25_N20
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita22\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita22~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(22) & (\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita21~COUT\ $ (GND))) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(22) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita21~COUT\ & VCC))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita22~COUT\ = CARRY((\inst|LPM_COUNTER_component|auto_generated|safe_q\(22) & !\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita21~COUT\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(22),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita21~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita22~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita22~COUT\);

-- Location: LCCOMB_X24_Y25_N22
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita23\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita23~combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(23) & (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita22~COUT\)) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(23) & ((\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita22~COUT\) # (GND)))
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita23~COUT\ = CARRY((!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita22~COUT\) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(23)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(23),
	datad => VCC,
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita22~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita23~combout\,
	cout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita23~COUT\);

-- Location: LCCOMB_X24_Y25_N24
\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita24\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita24~combout\ = \inst|LPM_COUNTER_component|auto_generated|safe_q\(24) $ (!\inst|LPM_COUNTER_component|auto_generated|counter_comb_bita23~COUT\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010110100101",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(24),
	cin => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita23~COUT\,
	combout => \inst|LPM_COUNTER_component|auto_generated|counter_comb_bita24~combout\);

-- Location: LCCOMB_X24_Y25_N28
\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~0_combout\ = ((\inst|LPM_COUNTER_component|auto_generated|safe_q\(21)) # ((\inst|LPM_COUNTER_component|auto_generated|safe_q\(22)) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(23)))) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(24))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110111111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(24),
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(21),
	datac => \inst|LPM_COUNTER_component|auto_generated|safe_q\(22),
	datad => \inst|LPM_COUNTER_component|auto_generated|safe_q\(23),
	combout => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~0_combout\);

-- Location: LCCOMB_X24_Y25_N26
\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~1\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~1_combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(18)) # (((!\inst|LPM_COUNTER_component|auto_generated|safe_q\(17)) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(20))) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(19)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011111111111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(18),
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(19),
	datac => \inst|LPM_COUNTER_component|auto_generated|safe_q\(20),
	datad => \inst|LPM_COUNTER_component|auto_generated|safe_q\(17),
	combout => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~1_combout\);

-- Location: LCCOMB_X24_Y25_N30
\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~2\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~2_combout\ = (((!\inst|LPM_COUNTER_component|auto_generated|safe_q\(15)) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(14))) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(13))) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(16))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0111111111111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(16),
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(13),
	datac => \inst|LPM_COUNTER_component|auto_generated|safe_q\(14),
	datad => \inst|LPM_COUNTER_component|auto_generated|safe_q\(15),
	combout => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~2_combout\);

-- Location: LCCOMB_X24_Y26_N0
\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~3\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~3_combout\ = (((\inst|LPM_COUNTER_component|auto_generated|safe_q\(9)) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(10))) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(12))) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(11))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111101111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(11),
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(12),
	datac => \inst|LPM_COUNTER_component|auto_generated|safe_q\(10),
	datad => \inst|LPM_COUNTER_component|auto_generated|safe_q\(9),
	combout => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~3_combout\);

-- Location: LCCOMB_X23_Y25_N10
\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~4\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~4_combout\ = (\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~3_combout\) # ((\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~2_combout\) # 
-- ((\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~1_combout\) # (\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111111110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~3_combout\,
	datab => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~2_combout\,
	datac => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~1_combout\,
	datad => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~0_combout\,
	combout => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~4_combout\);

-- Location: LCCOMB_X24_Y26_N4
\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~5\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~5_combout\ = (((\inst|LPM_COUNTER_component|auto_generated|safe_q\(8)) # (\inst|LPM_COUNTER_component|auto_generated|safe_q\(5))) # (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(7))) # 
-- (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(6))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111110111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(6),
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(7),
	datac => \inst|LPM_COUNTER_component|auto_generated|safe_q\(8),
	datad => \inst|LPM_COUNTER_component|auto_generated|safe_q\(5),
	combout => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~5_combout\);

-- Location: LCCOMB_X24_Y26_N6
\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~6\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~6_combout\ = (\inst|LPM_COUNTER_component|auto_generated|safe_q\(1)) # ((\inst|LPM_COUNTER_component|auto_generated|safe_q\(3)) # ((\inst|LPM_COUNTER_component|auto_generated|safe_q\(4)) # 
-- (\inst|LPM_COUNTER_component|auto_generated|safe_q\(2))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111111110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_COUNTER_component|auto_generated|safe_q\(1),
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(3),
	datac => \inst|LPM_COUNTER_component|auto_generated|safe_q\(4),
	datad => \inst|LPM_COUNTER_component|auto_generated|safe_q\(2),
	combout => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~6_combout\);

-- Location: LCCOMB_X24_Y26_N2
\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire\(0) = LCELL((!\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~4_combout\ & (!\inst|LPM_COUNTER_component|auto_generated|safe_q\(0) & 
-- (!\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~5_combout\ & !\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~6_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~4_combout\,
	datab => \inst|LPM_COUNTER_component|auto_generated|safe_q\(0),
	datac => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~5_combout\,
	datad => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~6_combout\,
	combout => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire\(0));

-- Location: CLKCTRL_G9
\inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~clkctrl\ : cycloneii_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~clkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~clkctrl_outclk\);

-- Location: PIN_D12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\CLK~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_CLK,
	combout => \CLK~combout\);

-- Location: CLKCTRL_G11
\CLK~clkctrl\ : cycloneii_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \CLK~clkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \CLK~clkctrl_outclk\);

-- Location: PIN_R22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\userNext~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_userNext,
	combout => \userNext~combout\);

-- Location: LCCOMB_X49_Y10_N18
\inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita1\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita1~combout\ = (\inst4|LPM_COUNTER_component|auto_generated|safe_q\(1) & (!\inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\)) # 
-- (!\inst4|LPM_COUNTER_component|auto_generated|safe_q\(1) & ((\inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\) # (GND)))
-- \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\ = CARRY((!\inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\) # (!\inst4|LPM_COUNTER_component|auto_generated|safe_q\(1)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst4|LPM_COUNTER_component|auto_generated|safe_q\(1),
	datad => VCC,
	cin => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\,
	combout => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita1~combout\,
	cout => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\);

-- Location: PIN_M22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\seleccion~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_seleccion,
	combout => \seleccion~combout\);

-- Location: CLKCTRL_G7
\seleccion~clkctrl\ : cycloneii_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \seleccion~clkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \seleccion~clkctrl_outclk\);

-- Location: LCFF_X49_Y10_N19
\inst4|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[1]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~clkctrl_outclk\,
	datain => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita1~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst4|LPM_COUNTER_component|auto_generated|safe_q\(1));

-- Location: LCCOMB_X49_Y10_N20
\inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita2\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita2~combout\ = (\inst4|LPM_COUNTER_component|auto_generated|safe_q\(2) & (\inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\ $ (GND))) # 
-- (!\inst4|LPM_COUNTER_component|auto_generated|safe_q\(2) & (!\inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\ & VCC))
-- \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\ = CARRY((\inst4|LPM_COUNTER_component|auto_generated|safe_q\(2) & !\inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \inst4|LPM_COUNTER_component|auto_generated|safe_q\(2),
	datad => VCC,
	cin => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\,
	combout => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita2~combout\,
	cout => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\);

-- Location: LCFF_X49_Y10_N23
\inst4|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[3]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~clkctrl_outclk\,
	datain => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita3~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst4|LPM_COUNTER_component|auto_generated|safe_q\(3));

-- Location: LCFF_X49_Y10_N21
\inst4|LPM_COUNTER_component|auto_generated|counter_reg_bit1a[2]\ : cycloneii_lcell_ff
PORT MAP (
	clk => \inst1|LPM_COMPARE_component|auto_generated|aneb_result_wire[0]~clkctrl_outclk\,
	datain => \inst4|LPM_COUNTER_component|auto_generated|counter_comb_bita2~combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst4|LPM_COUNTER_component|auto_generated|safe_q\(2));

-- Location: LCCOMB_X49_Y10_N12
\inst7~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst7~0_combout\ = (\inst4|LPM_COUNTER_component|auto_generated|safe_q\(4) & (\inst4|LPM_COUNTER_component|auto_generated|safe_q\(3) & (\inst4|LPM_COUNTER_component|auto_generated|safe_q\(2) & \inst4|LPM_COUNTER_component|auto_generated|safe_q\(1))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst4|LPM_COUNTER_component|auto_generated|safe_q\(4),
	datab => \inst4|LPM_COUNTER_component|auto_generated|safe_q\(3),
	datac => \inst4|LPM_COUNTER_component|auto_generated|safe_q\(2),
	datad => \inst4|LPM_COUNTER_component|auto_generated|safe_q\(1),
	combout => \inst7~0_combout\);

-- Location: LCCOMB_X49_Y10_N10
\inst7~1\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst7~1_combout\ = (\inst7~regout\) # ((!\inst4|LPM_COUNTER_component|auto_generated|safe_q\(0) & \inst7~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111010111110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst4|LPM_COUNTER_component|auto_generated|safe_q\(0),
	datac => \inst7~regout\,
	datad => \inst7~0_combout\,
	combout => \inst7~1_combout\);

-- Location: LCFF_X49_Y10_N11
inst7 : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~clkctrl_outclk\,
	datain => \inst7~1_combout\,
	aclr => \ALT_INV_seleccion~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst7~regout\);

-- Location: LCCOMB_X49_Y10_N0
\inst3~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \inst3~0_combout\ = (!\userNext~combout\ & (!\inst5~regout\ & \inst7~regout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000001100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \userNext~combout\,
	datac => \inst5~regout\,
	datad => \inst7~regout\,
	combout => \inst3~0_combout\);

-- Location: LCFF_X49_Y10_N1
inst5 : cycloneii_lcell_ff
PORT MAP (
	clk => \CLK~clkctrl_outclk\,
	datain => \inst3~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst5~regout\);

-- Location: PIN_R20,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\finalizacionP2~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => \inst5~regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_finalizacionP2);

-- Location: PIN_U19,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\YA~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => \inst7~regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_YA);

-- Location: PIN_R19,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\ALGO~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_ALGO);
END structure;


