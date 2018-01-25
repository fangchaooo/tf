#! /usr/bin/python3
import sys
import re
import os

os.system('sudo apt-get autoremove pandoc')
os.system('sudo apt-get install cabal-install')
os.system('cabal update')
os.system('cabal install pandoc')
os.system('sudo apt-get install pandoc')

path = input("Please input your markdown file path(using absolute path): ")
css_path = input("Please input your markdown.css path(using absolute path): ")
list = os.listdir(path)  
for root, dirs, files in os.walk(path):
    for filespath in files:
        if '.md' in filespath:
            try:
                path = os.mkdir(os.path.join(root, 'MD_TO_HTML'))
            except BaseException:
                s1 = os.path.join(root,filespath)
                new_names = re.findall(".*/(.*)\.md",s1)
                for new_name in new_names:
                    str = 'pandoc --css '+css_path+' ' + s1 + ' -o ' + root +'/MD_TO_HTML/'+new_name+'.html'
                    print(str)
                    os.system(str)

        

    
