import re
from urllib import request
import json

def get_context(url):
    with request.urlopen(url) as f:
        html = f.read().decode('gb18030','ignore')
        html = re.sub('<p class="text" style="TEXT\-INDENT:2em"><p.*?</p></p>', '', html)
        html = re.sub('<p class="text" style="TEXT\-INDENT:2em"><strong>.*?</strong></p>', '', html)
        html = re.sub('<p class="text" style="TEXT\-INDENT:2em">[<strong>|<b>].*?[</strong>|</b>]</p>', '', html)
        result = re.findall('<p class="text" style="TEXT\-INDENT:2em">(.*?)[<.*?DUMMY_TAG.*?]?</p>', html)
        context = "".join(result)
        context = re.sub('<!--DUMMY_TAG-->','',context)
        return context
def get_page_list(url):
    with request.urlopen(url) as f:
        data = f.read()
        html = data.decode('gb2312','ignore')  #可能回出现无法解码的字符，此时加个igore即可忽略这种错误
        result = re.findall('\{title:\'(.*?)\',url:\'(.*?)\',imgurl:.*?pubtime:\'(.*?)\'\}', html) #获取所有的页面列表信息
        return result
def get_tags(url):
    with request.urlopen(url) as f:
        html = f.read().decode('gb2312', 'ignore')
        result = re.findall('<meta name="keywords" content="(.*?)">[\s\S]*id:\'(\d*?)\'',html)
        #print(result)
        if len(result)<=0:
            return '',[]
        tags = result[0][0].split(',')
        #print(tags)
        return  result[0][1],tags[1:]
def get_list_contexts(url):
    url_information = get_page_list(url)
    print(url_information)
    contexts = []
    for page in url_information:
        tem = []
        context = {}
        index = {"index":{}}
        id, context["tags"] = get_tags(page[1])
        index["index"]["_id"] = id
        if len(context["tags"]) == 0:
            continue
        context["title"] = page[0]
        context["time"] = page[2]
        context["content"] = get_context(page[1])
        if len(context["content"]) == 0:
            continue
        tem.append(index)
        tem.append(context)
        #print(context)
        contexts.append(tem)
    #print(len(contexts))
    return contexts
def get_contexts():
    url = 'https://sports.qq.com/l/basket/nba/list20181018164449.htm'
    contexts = []
    contexts = contexts+get_list_contexts(url)
    #print(contexts)
    for i in range(2,3):
        tem_url = 'https://sports.qq.com/l/basket/nba/list20181018164449_'+str(i)+'.htm'
        contexts += get_list_contexts(tem_url)

    with open('data.txt','w',encoding='gbk') as f:
        for array in contexts:
            for tem in array:
                json_format = json.dumps(tem,ensure_ascii=False)
                f.write(json_format+'\n')
            f.write('\n')
if __name__ == '__main__':
    get_contexts()
    #ls = get_page_list('https://sports.qq.com/l/basket/nba/list20181018164449.htm')
