require 'asset_tag_helper'

module AssetsHelper
  def asset_title_for(asset)
    asset.title.blank? ? asset.filename : asset.title
  end

  def asset_image_for(asset, style = :tiny, options = {})
    image_tag(*asset_image_args_for(asset, style, options))
  end

  def asset_image_args_for(asset, style = :tiny, options = {})
    # thumb_size = Array.new(2).fill(Asset.attachment_options[:thumbnails][thumbnail].to_i).join('x')
    # options    = options.reverse_merge(:title => "#{asset.title} \n #{asset.tags.join(', ')}", :size => thumb_size)
    # if asset.movie?
    #   ['/images/adva_cms/icons/assets/video.png', options]
    # elsif asset.audio?
    #   ['/images/adva_cms/icons/assets/audio.png', options]
    # elsif asset.pdf?
    #   ['/images/adva_cms/icons/assets/pdf.png', options]
    # elsif asset.other?
    #   ['/images/adva_cms/icons/assets/doc.png', options]
    # elsif asset.thumbnails_count.zero?
    #   [asset.public_filename, options]
    # else
      [asset.base_url(style), options]
    # end
  end
end