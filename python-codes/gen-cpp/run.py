# /usr/bin/env python
# coding: utf-8

# 遍历所有的类，类名、父类名
# 对每个类
#  遍历所有的模板文件
#  生成目标文件
#  写入目标位置

import os
import re
import shutil
import config

class Generater(object):
    def run(self):
        shutil.rmtree(os.path.join('.', 'out'), True)
        self.getTemplateFiles()
        self.generate('', config.classDiagram)

    def generate(self, parentClassName, classDiagram):
        for key, value in classDiagram.items():
            if parentClassName:
                params = {
                    'className' : '',
                    'parentClassName' : '',
                    'headerMacro' : '',
                    }
                params['className'] = key
                params['parentClassName'] = parentClassName
                params['headerMacro'] = (key + '_H').upper()

                for fileName in self.files:
                    self.generateFile(fileName, params)

            self.generate(key, value)

    def getTemplateFiles(self):
        self.files = []
        for dirpath, dirnames, filenames in os.walk(os.path.join('.', 'templates')):
            for filename in filenames:
                self.files.append(os.path.join(dirpath, filename))

    def generateFile(self, fileName, params):
        with file(fileName, 'r') as f:
            txt = f.read()
            txt = re.sub(r'{class-name}', params['className'], txt)
            txt = re.sub(r'{parent-class-name}', params['parentClassName'], txt)
            txt = re.sub(r'{header-macro}', params['headerMacro'], txt)

            destPath = os.path.join('.', 'out')
            
            if fileName.endswith('.h'):
                destPath = os.path.join(destPath, 'include')
            else:
                destPath = os.path.join(destPath, 'src')

            try:
                os.makedirs(destPath)
            except:
                pass

            _, fileExt = os.path.splitext(fileName)

            destFileName = os.path.join(destPath,
                                        params['className'] + fileExt)
            with file(destFileName, 'w') as destFile:
                destFile.write(txt)
    
if __name__ == "__main__":
    gen = Generater()
    gen.run()

