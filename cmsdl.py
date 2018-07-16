from urllib.request import urlopen, urlretrieve
from urllib.parse import urljoin
from operator import itemgetter
import re, os
import os.path


def dltestcases(base_url, task_id, task_name, contest_name):
	html = urlopen(base_url + '/task/' + task_id).read().decode()
	match = re.findall(
		r"show_file\('([^']+)','\.\./file/([0-9a-z]+)/",
		html)
	for e in match:
		testcase_url = base_url + '/file/' + e[1] + '/' + e[0]
		filepath = os.path.join(contest_name, task_name, 'testcases', e[0])
		print('Downloading ' + filepath)
		urlretrieve(testcase_url, filepath)

	match = re.search(r'/([0-9a-z]+)/statement\.pdf', html)
	pdf_url = base_url + '/file/' + match.group(1) + '/statement.pdf'
	urlretrieve(pdf_url, os.path.join(contest_name, task_name, task_name+'.pdf'))

def gettasks(base_url, contest_id):
	html = urlopen(base_url + '/tasklist/' + contest_id).read().decode()
	match = re.findall(r'<a href="\.\./task/(\d\d)">([^<>]+)', html)
	res = []
	for e in match:
		task_id = e[0]
		task_name = e[1]
		res.append(dict(task_id=task_id, task_name=task_name))
	return res

def dlcontest(base_url, contest_id, contest_name):
	os.mkdir(contest_name)
	tasks = gettasks(base_url, contest_id)
	print('Task list:')
	for e in tasks:
		print('{} (id = {})'.format(e['task_name'], e['task_id']))
		os.mkdir(os.path.join(contest_name, e['task_name']))
		os.mkdir(os.path.join(contest_name, e['task_name'], 'testcases'))
		dltestcases(base_url, e['task_id'], e['task_name'], contest_name)

# os.chdir('Tainan Senior High School First Grade Contest 2017')
# gettasks('http://localhost:9487', '8', 'aaa')
dlcontest('http://localhost:9487', '9', '2017 Tainan Senior High Schools Contest for First Grades')
# dltestcases('http://localhost:9487', '34', 'Informatics', 'aaa')
# input('...')
