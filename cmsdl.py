from requests.auth import HTTPBasicAuth
import requests
import re, os, os.path, logging


def dltestcases(session, base_url, task_id, task_name, contest_name):
	html = session.get(base_url + '/task/' + task_id).text
	match = re.findall(
		r"show_file\('(.+?)','\.\./file/([0-9a-z]+)/",
		html)
	for e in match:
		testcase_url = base_url + '/file/' + e[1] + '/' + e[0]
		filepath = os.path.join(contest_name, task_name, 'testcases', e[0])
		print('Downloading ' + filepath)
		open(filepath, 'wb').write(session.get(testcase_url).content)

	match = re.search(r'/([0-9a-z]+)/statement\.pdf', html)
	if match:
		pdf_url = base_url + '/file/' + match.group(1) + '/statement.pdf'
		open(os.path.join(
			contest_name,
			task_name,
			task_name+'.pdf'), 'wb').write(session.get(pdf_url).content)

def gettasks(session, base_url, contest_id):
	html = session.get(base_url + '/contest/' + contest_id + '/tasks').text
	print(html)
	match = re.findall(r'<a href="\.\./\.\./task/(\d\d)">([^<>]+)', html)
	return [ {'task_id': e[0], 'task_name': e[1]} for e in match ]

def dlcontest(base_url, contest_id, contest_name):
	session = requests.Session()
	html = session.get(base_url).text
	_xsrf = re.search(r'<input type="hidden" name="_xsrf" value="([^"]+)"', html).group(1)
	session.post(base_url + '/login',
		data={'username': 'soytw', 'password': '8787887', '_xsrf': _xsrf})

	os.mkdir(contest_name)
	tasks = gettasks(session, base_url, contest_id)
	print('Task list:')
	for e in tasks:
		print('{} (id = {})'.format(e['task_name'], e['task_id']))
		os.mkdir(os.path.join(contest_name, e['task_name']))
		os.mkdir(os.path.join(contest_name, e['task_name'], 'testcases'))

		dltestcases(session, base_url, e['task_id'], e['task_name'], contest_name)

# os.chdir('Tainan Senior High School First Grade Contest 2017')
# gettasks('http://localhost:9487', '8', 'aaa')
#dlcontest('http://localhost:9487', '9', '2017 Tainan Senior High Schools Contest for First Grades')
logging.basicConfig(level='DEBUG')
dlcontest('http://cms.tfcis.org/admin', '14', 'xxx14')
# dltestcases('http://localhost:9487', '34', 'Informatics', 'aaa')
# input('...')
