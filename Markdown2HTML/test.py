#! /usr/bin/python3
import sys
import re
import os

os.system('sudo apt-get autoremove pandoc')
os.system('sudo apt-get install cabal-install')
os.system('cabal update')
os.system('cabal install pandoc')
os.system('sudo apt-get install pandoc')

path = '/home/moro/Downloads'
css_path = '/home/moro/Downloads/UntitledFolder/1.css'
list = os.listdir(path)  
for root, dirs, files in os.walk(path):
    for filespath in files:
        if '.md' in filespath:
            path = os.mkdir(os.path.join(root, 'MD_TO_HTML'))
            s1 = os.path.join(root,filespath)
            new_names = re.findall(".*/(.*)\.md",s1)
            for new_name in new_names:
                str = 'pandoc --css '+css_path+' ' + s1 + ' -o ' + root +'/MD_TO_HTML/'+new_name+'.html'
                os.system(str)

        

    
