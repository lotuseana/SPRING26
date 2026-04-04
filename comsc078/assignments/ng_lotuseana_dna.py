def clean_sequence(sequence: str):
	result = ""
	for char in sequence:
		if (char.isalpha()):
			result += char.upper()
	return result

def main():
	ref = { "TTT": "Phe", "TTC": "Phe", "TTG": "Leu", "TTA": "Leu",
			"TCT": "Ser", "TCC": "Ser", "TCG": "Ser", "TCA": "Ser",
			"TGT": "Cys", "TGC": "Cys", "TGG": "Trp", "TGA": "***",
			"TAT": "Tyr", "TAC": "Tyr", "TAG": "***", "TAA": "***",
			
			"CTT": "Leu", "CTC": "Leu", "CTG": "Leu", "CTA": "Leu",
			"CCT": "Pro", "CCC": "Pro", "CCG": "Pro", "CCA": "Pro",
			"CGT": "Arg", "CGC": "Arg", "CGG": "Arg", "CGA": "Arg",
			"CAT": "His", "CAC": "His", "CAG": "Gln", "CAA": "Gln",
			
			"GTT": "Val", "GTC": "Val", "GTG": "Val", "GTA": "Val",
			"GCT": "Ala", "GCC": "Ala", "GCG": "Ala", "GCA": "Ala",
			"GGT": "Gly", "GGC": "Gly", "GGG": "Gly", "GGA": "Gly",
			"GAT": "Asp", "GAC": "Asp", "GAG": "Glu", "GAA": "Glu",
			
			"ATT": "Ile", "ATC": "Ile", "ATG": "Met", "ATA": "Ile",
			"ACT": "Thr", "ACC": "Thr", "ACG": "Thr", "ACA": "Thr",
			"AGT": "Ser", "ACG": "Ser", "AGG": "Arg", "AGA": "Arg",
			"AAT": "Asn", "AAC": "Asn", "AAG": "Lys", "AAA": "Lys" }
	
	cont = True
	
	while cont:
		sequence = input("enter nucleotide sequence or press ENTER to quit: ")
		if (sequence == ""):
			cont = False
		else:
			cleaned = clean_sequence(sequence)
			if (len(cleaned) % 3 == 0 and len(cleaned) >= 3):
				for i in range(len(cleaned) // 3):
					triple = cleaned[3 * i : 3 * i + 3]
					print(f"{triple} {ref.get(triple, "invalid sequence")}")
			else:
				print("error: You must give complete triples.")
	
main()