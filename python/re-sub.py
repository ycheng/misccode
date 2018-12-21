
import re

urls = [
    "deb-src https://private-ppa.launchpad.net/oem-solutions-group/ppa/ubuntu bionic main",
    "deb-src https://(aaa)@(bbb):private-ppa.launchpad.net/oem-solutions-group/ppa/ubuntu bionic main",
    "deb-src https://aaa@bbb:private-ppa.launchpad.net/oem-solutions-group/ppa/ubuntu bionic main",
    "deb-src http://aaa@bbb:private-ppa.launchpad.net/oem-solutions-group/ppa/ubuntu bionic main",
    "deb http://aaa@bbb:private-ppa.launchpad.net/oem-solutions-group/ppa/ubuntu bionic main",
    "deb ftp://aaa@bbb:private-ppa.launchpad.net/oem-solutions-group/ppa/ubuntu bionic main",
    "# deb ftp://aaa@bbb:private-ppa.launchpad.net/oem-solutions-group/ppa/ubuntu bionic main",
    "# deb ftp://aaa@bbb:private-ppa.launchpad.net/oem-solutions-group/ppa/ubuntu bionic main # bbb"
    ]

matcher = re.compile("(https://|http://|ftp://).*?@.*?:")
for url in urls:
    result = matcher.sub(r"\1USER@PWD:", url, count=1)
    print(result)
