import xml.etree.ElementTree as ET
from collections import defaultdict

def parse_thesaurus(thesaurus_xml):
    root = ET.fromstring(thesaurus_xml)
    term_relations = defaultdict(list)
    top_level_terms = set()
    
    for term_info in root.findall('TermInfo'):
        term = term_info.find('T').text
        broader_terms = [bt.text for bt in term_info.findall('BT')]
        if not broader_terms:
            top_level_terms.add(term)
        for broader_term in broader_terms:
            term_relations[term].append(broader_term)
    
    return term_relations, top_level_terms

def count_term_occurrences(text, term_relations, top_level_terms):
    counts = defaultdict(int)
    
    words = text.split()
    for word in words:
        word = word.rstrip(',.!?').lower()
        if word in term_relations:
            queue = [word]
            visited = set()
            while queue:
                current_term = queue.pop()
                visited.add(current_term)
                broader_terms = term_relations[current_term]
                for broader_term in broader_terms:
                    if broader_term not in visited:
                        queue.append(broader_term)
                        if broader_term in top_level_terms:
                            counts[broader_term] += 1
    
    return counts

def main(thesaurus_xml, text):
    term_relations, top_level_terms = parse_thesaurus(thesaurus_xml)
    counts = count_term_occurrences(text, term_relations, top_level_terms)
    
    sorted_topics = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
    
    for topic, count in sorted_topics:
        print(f'{topic} = {count}')

thesaurus_xml = input()
while 1:
    s = input()
    thesaurus_xml += "\n" + s
    if s == "</Thesaurus>":
        break
text = input()

# print(thesaurus_xml)
# print(text)
main(thesaurus_xml, text)
