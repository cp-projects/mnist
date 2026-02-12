import os
import urllib.request

MNIST_URLS = {

    "train_images": "https://raw.githubusercontent.com/fgnt/mnist/master/train-images-idx3-ubyte.gz",
    "train_labels": "https://raw.githubusercontent.com/fgnt/mnist/master/train-labels-idx1-ubyte.gz",
    "test_images": "https://raw.githubusercontent.com/fgnt/mnist/master/t10k-images-idx3-ubyte.gz",
    "test_labels": "https://raw.githubusercontent.com/fgnt/mnist/master/t10k-labels-idx1-ubyte.gz",
}

os.makedirs("data", exist_ok=True)

for name, url in MNIST_URLS.items():
    path = os.path.join("data", os.path.basename(url))
    if not os.path.exists(path):
        print(f"Downloading {name}...")
        urllib.request.urlretrieve(url, path)
    else:
        print(f"{name} already exists, skipping.")
 
