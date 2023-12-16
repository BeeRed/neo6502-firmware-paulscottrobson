# *******************************************************************************************
# *******************************************************************************************
#
#		Name : 		makeprogram.py
#		Purpose :	Generate test program.
#		Date :		16th December 2023
#		Author : 	Paul Robson (paul@robsons.org.uk)
#
# *******************************************************************************************
# *******************************************************************************************

import os,sys,math,re,random
from tokens import *
from tokeniser import *

class TestProgram(object):
	def __init__(self):
		self.identStore = IdentifierStore()
		for c in ["A","O","P","X","Y"]:
			self.identStore.add(c)
		self.tokenSet = TokenSet()
		self.tokenWorker = Tokeniser(self.identStore)
		self.tokeniser = []
		self.sourceLines = []
		self.program = {}

		for i in range(0,22):
			ln = i * 10 + 1000
			self.addLine(ln,"print {0} ${0} > >= adc clear \"Hi\":4.73 a_{1}".format(ln,(i+1)*11))
	#
	def addLine(self,lineNumber,code):
		self.sourceLines.append("{0} {1}".format(lineNumber,code))
		if code != "":
			self.program[lineNumber] = self.tokenWorker.tokenise(code)
		else:
			del self.program[lineNumber]
	#
	def renderInput(self,h):
		h.write(";\n;\tThis file is automatically generated.\n;\n")
		for l in self.sourceLines:
			h.write("\t.text\t{0},'{1}'\n".format(len(l),l))
		h.write("\t.byte\t0\n")
	#
	def renderTokenised(self,h):
		h.write(bytes(self.identStore.render()))
		lNo = [x for x in self.program.keys()]
		lNo.sort()
		for l in lNo:
			line = [0,l & 0xFF,l >> 8] + self.program[l] + [self.tokenSet.getByName("!!end").getID()]
			line[0] = len(line)
			h.write(bytes(line))
		h.write(bytes([0]))

prg = TestProgram()
prg.renderInput(open("sources/generated/inputtoken.dat","w"))
prg.renderTokenised(open("build/token_test.dat","wb"))